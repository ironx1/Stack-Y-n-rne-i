#include <stdio.h>
#include <stdlib.h>

int *stack;
int size=2;
int top=-1;
void push(int data);
int pop();
int main(int argc, char const *argv[])
{
    stack = (int*)malloc(size*sizeof(int));
    int sel,num,counter=1;
    printf("Hoşgeldiniz\n\n");
    while (counter)
    {
        printf("\n1. Yığına Ekle\n2. Yığından Çıkar\n3. Yığını Listele\n4. Çıkış Yap\nSeçim Yap(1/2/3/4): ");
        scanf("%d",&sel);
        switch (sel)
        {
        case 1:
            printf("Eklemek İstediğiniz Sayı: ");
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            printf("\n%d yığından çıkarıldı!\n",pop());
            break;
        case 3:
            printf("\n");
            for (int i = 0; i <= top; i++)
            {
                printf("%d ", stack[i]);
            }
            printf("\n");
            break;
        case 4:
            printf("Çıkış Yapılıyor...\n");
            counter = 0;  
        default:
            //printf("Hatalı Giriş\n");
            break;
        }
    }
    return 0;
}
void push(int data){
    top++;
    if (top>=size)
    {
        int *newstack = (int*)malloc(size*2*sizeof(int));
        for (int i = 0; i < size; i++)
        {
            newstack[i] = stack[i];
        }
        free(stack);
        stack = newstack;
        size*=2;
    }
    stack[top] = data;
    printf("\n%d yığına eklendi!\n",data);
}
int pop(){
    if (top<0)
    {
        printf("\nYığında veri yok!\n");
        exit(1);
    }
    else if (top==size/4)
    {
        int *newstack = (int*)malloc((size/2)*sizeof(int));
        for (int i = 0; i < size/2; i++)
        {
            newstack[i] = stack[i];
        }
        free(stack);
        stack = newstack;
        size /= 2;
    }
    
    return stack[top--];
}
