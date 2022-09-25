FCPU::FCPU (std::string file)
{
    set_key ();
    fin.open (file);

    while (!fin.eof ())
    {
        std::string op;

        fin >> op;

        if (op == "mov") { mov (); }
        else if (op == "add") { add (); }
        else if (op == "sub") { sub (); }
        else if (op == "mul") { mul (); }
        else if (op == "div") { div (); }
        else if (op == "xor") { _xor (); }
        else if (op == "jmp") { jmp (file); }
        else if (op == "cmp") { _cmp (); }
        else if (op == "jle") { jle (file);}
    }
}

FCPU::~FCPU ()
{
    fin.close ();
}

void FCPU::set_key ()
{

    rm["r1"] = 0;
    rm["r2"] = 0;
    rm["r3"] = 0;
    rm["r4"] = 0;
    rm["r5"] = 0;
    rm["r6"] = 0;
    rm["r7"] = 0;
    rm["r8"] = 0;
    rm["r9"] = 0;
    rm["r10"] = 0;
}

void FCPU::mov ()
{
    std::string r;
    std::string sv;
    fin >> r;
    fin >> sv;
    if ('0' <= sv[0] && '9' >= sv[0])
    {
        rm[r] = std::stoi (sv);
        return;
    }
    rm[r] = rm[sv];
}

void FCPU::add ()
{
    std::string r;
    std::string sv;
    fin >> r;
    fin >> sv;
    if ('0' <= sv[0] && '9' >= sv[0])
    {
        rm[r] += std::stoi (sv);
        return;
    }
    rm[r] += rm[sv];
}

void FCPU::sub ()
{
    std::string r;
    std::string sv;
    fin >> r;
    fin >> sv;
    if ('0' <= sv[0] && '9' >= sv[0])
    {
        rm[r] -= std::stoi (sv);
        return;
    }
    rm[r] -= rm[sv];
}

void FCPU::mul ()
{
    std::string r;
    std::string sv;
    fin >> r;
    fin >> sv;
    if ('0' <= sv[0] && '9' >= sv[0])
    {
        rm[r] *= std::stoi (sv);
        return;
    }
    rm[r] *= rm[sv];
}


void FCPU::div ()
{
    std::string r;
    std::string sv;
    fin >> r;
    fin >> sv;
    if ('0' <= sv[0] && '9' >= sv[0])
    {
        rm[r] = std::stoi (sv);
        return;
    }
    rm[r] /= rm[sv];
}

 void FCPU::_xor ()
{
    std::string r;
    std::string sv;
    fin >> r;
    fin >> sv;
    if ('0' <= sv[0] && '9' >= sv[0])
    {
        rm[r] = rm[r] ^ std::stoi (sv);
        return;
    }
    rm[r] = rm[r] ^ rm[sv];
    return;
}

void FCPU::jmp (std::string file)
{
    std::string label;
    fin >> label;
    label += ':';
    fin.close ();

    fin.open (file);

    while (!fin.eof ())
    {
        std::string point;
        fin >> point;
        if (point == label) {
        return;
        }
    }
}

void FCPU::_cmp ()
{
    std::string r;
    std::string sv;
    fin >> r;
    fin >> sv;
    if ('0' <= sv[0] && '9' >= sv[0])
    {
        int tmp = std::stoi (sv);

        if (rm[r] > tmp) { cmp = 1; }
        else if (rm[r] == tmp) { cmp = 0; }
        else { cmp = -1; }
    }
    else
    {
        if (rm[r] > rm[sv]) { cmp = 1; }
        else if (rm[r] == rm[sv] ) { cmp = 0; }
        else { cmp = -1; }
    }
    
}

void FCPU::jle (std::string file)
{
    if (-1 == cmp || 0 == cmp) { jmp (file); }
}

void FCPU::jge (std::string file)
{
    if (1 == cmp || 0 == cmp) { jmp (file); }
}