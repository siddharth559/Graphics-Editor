#include<simplecpp>


class rectangular_range
{
    public:
        float x1,x2,y1,y2;
        rectangular_range(float,float,float,float);
        bool in_region(float,float);
};

int canvasss = initCanvas("PAINT",800,700);//const char window_title[]="Simplecpp Canvas", int w=500, int h=500);

rectangular_range* ranges_button = (rectangular_range*)malloc(sizeof(rectangular_range)*40);
int ranges_button_index = 0;

int rect_index = 0;
int cir_index = 0;
int line_index = 0;
Rectangle rects[40];
Circle cirs[40];
Line lines[40];
Color main_col = COLOR("blue");




class button
{
        
    public:
        void isclicked(void);
        bool is_visible = 0;
        char * text;
        Color bg;
        Color fg;
        int width;
        int height;
        void (*command)(void);
        int centrex;
        int centrey;
        button(char *, Color, Color, int, int, void (*fun_ptr)(void),int,int);  //text bg fg width height command
        void grid(void); // x,y    
        void hide(void);
        void change_col(void);
        char shape_t = '\0';
        int index;
        int config_col_but;
        void configure_shape_but(int, char);
        void configure_color_but(void);
};



