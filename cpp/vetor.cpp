class Vec2{
    private:
        float x;
        float y;
    public:
        Vec2(float i, float j){
            x =  i;
            y = j;
        };
        void set(float i, float j){
            x = i;
            y= j;
        };
        void incerment(float i,float j){
            x+=i;
            y+=j;
        };
        
}