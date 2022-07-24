class Key {
    private:
        const int maxLength;
        int length;
        char* key;
    public:
        Key();
        void setKey();
        int getLength();
        int getOffset(int position);
};

class Text {
    private:
        const int maxLength;
        int length;
        char* plaintext;
        char* encrypted;
    public:
        Text();
        int openFile(char *fileName);
        int getLength();
        int encrypt(Key* key);
};