#include "header.h"


rectangular_range :: rectangular_range(float xin, float yin, float xout, float yout)
{
    x1=xin;
    y1=yin;
    x2=xout;
    y2=yout;
}
bool rectangular_range :: in_region(float x, float y)
{
    return ((x>=x1) && (y>=y1) && (x<=x2) && (y<=y2));
}

button :: button(char * TEXT, Color BG, Color FG, int WIDTH, int HEIGHT, void (*fun_ptr) (void),int posx , int posy)
{

    int l = 0;
    for(; TEXT[l]; l++);
    l++;
    text = new char[l];
    bg = BG;
    fg = FG;

    for(int i = 0; i<l; i++) text[i] = TEXT[i];

    width = WIDTH;
    height = HEIGHT;
    command = fun_ptr;

    centrex = posx;
    centrey = posy;

    ranges_button[ranges_button_index] = rectangular_range(centrex-width/2,centrey-height/2,centrex+width/2,centrey+height/2);
    ranges_button_index++;

}

void button :: grid(void)
{
    is_visible = 1;
    Rectangle shadow(centrex+4,centrey+4,width-1,height-1);
    shadow.setFill(1);
    Rectangle r(centrex, centrey, width-3, height-3);
    Text t(centrex, centrey, text);
    t.setColor(fg);
    r.setColor(bg);
    r.setFill(1);
    shadow.imprint();
    r.imprint();
    t.imprint();

}

void button :: hide(void)
{
    is_visible = 0;
    Rectangle shadow_q(centrex,centrey,width+8,height+6);
    shadow_q.setColor(COLOR("white"));
    shadow_q.setFill(1);
    shadow_q.imprint();
    for(int i = 0; i<3 ; i++)rects[i].imprint();
}

void button :: isclicked(void)
{
    change_col();
    if (config_col_but == 1) configure_color_but();
    else (*command)();
    Rectangle r(centrex, centrey, width-3, height-3);
    Text t(centrex, centrey, text);
    t.setColor(fg);
    r.setColor(bg);
    r.setFill(1);
    r.imprint();
    t.imprint();
}

void button :: change_col(void)
{
    Rectangle r(centrex, centrey, width-3, height-3);
    Text t(centrex, centrey, text);
    t.setColor(COLOR("white"));
    r.setColor(COLOR("blue"));
    r.setFill(1);
    r.imprint();
    t.imprint();
}

void button ::configure_shape_but(int index_in_array, char shape)
{
    index = index_in_array;
    shape_t = shape;
}

void button :: configure_color_but(void)
{ 
    main_col = bg;
    Rectangle color_to_be_filled = Rectangle(40,520,40,40);
    color_to_be_filled.setColor(main_col);
    color_to_be_filled.setFill(1);
    color_to_be_filled.imprint();
}


