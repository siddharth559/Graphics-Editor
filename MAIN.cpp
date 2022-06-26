#include<simplecpp>
#include "functions.h"
#include<fstream>


button* buttons = (button*)malloc(sizeof(button)*40);


int button_index = 0;
bool BUTTONS_VISIBLE = 0; 


void ccc(void)
{
    cout << "HELLO";
}

void fillcol()
{
    rects[1].setColor(COLOR("red"));
    rects[1].setFill(1);
}
void make_rect(void)
{
    rectangular_range draw_frame(440-650/2,380-250,440+650/2,380+500/2);
    int p1 = getClick();
    int p2 = getClick();
    int p1x = p1/65536; int p1y = p1 % 65536;
    int p2x = p2/65536; int p2y = p2 % 65536;

    if(draw_frame.in_region(p1x,p1y) && draw_frame.in_region(p2x,p2y))
    {
    rects[rect_index] = Rectangle((p1x+p2x)/2,(p1y+p2y)/2,abs(p1x-p2x),abs(p1y-p2y));
    button R("",COLOR("green"),COLOR("orange"),20,20,&fillcol,(p1x+p2x)/2,(p1y+p2y)/2);
    buttons[button_index] = R;
    buttons[button_index].configure_shape_but(rect_index,'r');
    button_index++;
    rects[rect_index].imprint();
    rect_index++; 
    }   
    
}

void make_cir(void)
{
    int p1 = getClick();
    int p2 = getClick();
    int p1x = p1/65536; int p1y = p1 % 65536;
    int p2x = p2/65536; int p2y = p2 % 65536;

    cirs[cir_index] = Circle((p1x),(p1y),sqrt((p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y)));
    button B("",COLOR("green"),COLOR("orange"),20,20,&ccc,p1x,p1y);
    buttons[button_index] = B;
    buttons[button_index].configure_shape_but(cir_index,'c');
    button_index++;
    cirs[cir_index].imprint();
    cir_index++;
}

void make_line(void)
{
    int p1 = getClick();
    int p2 = getClick();
    int p1x = p1/65536; int p1y = p1 % 65536;
    int p2x = p2/65536; int p2y = p2 % 65536;
    Line l(p1x,p1y,p2x,p2y);
    lines[line_index] = l;
    line_index++;
    l.setColor(main_col);
    l.imprint();
}

void show_shape_buts(void)
{
    if (BUTTONS_VISIBLE == 0)
    {
    for(int i=0; i<button_index; i++) if(buttons[i].shape_t) buttons[i].grid();
    BUTTONS_VISIBLE = 1;
    }
    else if (BUTTONS_VISIBLE == 1)
    {
        for(int i=0; i<button_index; i++) if(buttons[i].shape_t) buttons[i].hide();
        BUTTONS_VISIBLE = 0;
    }
}

void save_file(void)
{
    ofstream file;
    file.open("File1.txt", ios::out);
    file.write( (char *) & rects, sizeof(rects));
    file.write( (char *) & cirs, sizeof(cirs));
    file.write( (char *) & lines, sizeof(lines));
    file.close();
}

void open_file(void)
{
    ifstream file;
    file.open("File1.txt", ios::in);
    file.read( (char *) & rects, sizeof(rects));
    file.read( (char *) & cirs, sizeof(rects));
    file.read( (char *) & lines, sizeof(rects));
    for(int i; i<40; i++)
    {
        rects[i].imprint();
    }
    for(int i; i<40; i++)
    {
        cirs[i].imprint();
    }
    for(int i; i<40; i++)
    {
        lines[i].imprint();
    }
}
main_program{
    

    Rectangle frame(440,380,650,500);
    Rectangle present_col(40,520,40,40);
    present_col.setColor(main_col);
    present_col.setFill(1);
    present_col.imprint();
    present_col.forward(1000);

    
    buttons[button_index] = button("rectangle", COLOR("red"), COLOR("blue"), 100, 40, &make_rect,50,280);
    button_index++;

    buttons[button_index] = button("circle",COLOR("red"),COLOR("blue"),100,40,&make_cir,50,320);
    button_index++;

    buttons[button_index] = button("line",COLOR("red"),COLOR("blue"),100,40,&make_line,50,360);
    button_index++;

    buttons[button_index] = button("fill",COLOR("red"),COLOR("blue"),100,40,&show_shape_buts,50,400);
    button_index++;

    buttons[button_index] = button("",COLOR("green"),COLOR("orange"),20,20,&ccc,10,440);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("yellow"),COLOR("orange"),20,20,&ccc,10,460);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("red"),COLOR("orange"),20,20,&ccc,30,440);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("blue"),COLOR("orange"),20,20,&ccc,30,460);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("orange"),COLOR("orange"),20,20,&ccc,50,440);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("indigo"),COLOR("orange"),20,20,&ccc,50,460);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("black"),COLOR("orange"),20,20,&ccc,10,480);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("white"),COLOR("orange"),20,20,&ccc,30,480);
    buttons[button_index].config_col_but = 1;
    button_index++;
    buttons[button_index] = button("",COLOR("mustard"),COLOR("orange"),20,20,&ccc,50,480);
    buttons[button_index].config_col_but = 1;
    button_index++;
    

    buttons[button_index] = button("SAVE",COLOR("green"),COLOR("orange"),100,20,&save_file,50,40);
    button_index++;
    buttons[button_index] = button("OPEN",COLOR("green"),COLOR("orange"),100,20,&open_file,150,40);
    button_index++;
    buttons[button_index] = button("demo",COLOR("green"),COLOR("orange"),100,20,&ccc,250,40);
    button_index++;
    
    
    for(int i=0; i<button_index; i++) buttons[i].grid();
    
    

    
    
    
    int final_ind = button_index;


    while (1){

        int w = getClick();
        int x =  w/65536; int y = w % 65536;

        for(int i = 0; i<ranges_button_index; i++){
            if (ranges_button[i].in_region(x,y)) 
                if (buttons[i].is_visible) {
                
                    if (i<final_ind)  buttons[i].isclicked(); 
                    
                    else if (i>=final_ind) {

                        int indi = buttons[i].index;
                        
                        if(buttons[i].shape_t == 'r') 
                            {      
                            rects[indi].setColor(main_col);
                            rects[indi].setFill(1);
                            rects[indi].imprint();
                            }
                        else if(buttons[i].shape_t == 'c') 
                            {
                            cirs[indi].setColor(main_col);
                            cirs[indi].setFill(1);
                            cirs[indi].imprint();
                            }
                        }}
        }
    }

    

}
