class my_string
{
public:
    my_string(const char*);
    my_string(const char);
    my_string();
    my_string(const my_string&);

    my_string sub_str(int b, int e);
    void print();
    ~my_string();

private:
    char* _str;
    int _size;
};
