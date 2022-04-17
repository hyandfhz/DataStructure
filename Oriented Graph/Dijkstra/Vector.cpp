template <typename item>
class Vector {
   private:
    item data[10010];
    int length;

   public:
    void init() { length = 0; }
    void pushData(item xData) { data[++length] = xData; }
    void popData(int x) {
        for (int i = length--; i > x; i--) {
            data[i] = data[i - 1];
        }
    }
    int getLength() { return length; }
    item getData(int x) { return data[x]; }
};