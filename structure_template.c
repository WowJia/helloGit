//按钮a、b、c 分别对应开灯、关灯、灯闪烁
#include <stdio.h>

typedef void (*button_fuc) (void);

void light_on(void)
{
    printf("open the light !\n");
}

void light_off(void)
{
    printf("close the light !\n");
}

void light_blink(void)
{
    printf("blink the light !\n");
}

typedef struct
{
    char button;
    button_fuc fuc;
}button_fuc_list;



button_fuc_list ButtonFucList[] = 
{
    {'a', light_on},
    {'b', light_off},
    {'c', light_blink}
};

void process_button_fuc(char button)
{
    int size = sizeof(ButtonFucList) / sizeof(button_fuc_list);
    for (int i = 0; i < size; i++)
    {   
        if (ButtonFucList[i].button == button)
        {
            ButtonFucList[i].fuc();
            return;
        } 
    }

    printf("Button fucntion not found !\n");
}

int main()
{
    process_button_fuc('a');
    process_button_fuc('b');
    process_button_fuc('c');
    process_button_fuc('d');
    return 0;
}