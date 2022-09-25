class FCPU 
{
    public:
        FCPU () = delete;
        FCPU (const FCPU&) = delete;
        FCPU (FCPU&&) = delete;
        FCPU& operator = (const FCPU&) = delete;
        FCPU& operator = (FCPU&&) = delete;
        FCPU (std::string);
        ~FCPU ();
    private:
        void set_key ();
        void mov ();
        void add ();
        void sub ();
        void mul ();
        void div ();
        void _xor ();
        void jmp (std::string);
        void _cmp ();
        void jle (std::string);
        void jge (std::string);
    private:
        int cmp;
        std::ifstream fin;
        //std::map<std::string, void (FCPU::*) (std::string, std::string)> fm;
        std::map<std::string, int> rm;
};