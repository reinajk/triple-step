#include <stdio.h>
#include <math.h>
int main()
{
    double sci[20] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70};
    double eng[20] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

    double sci_ave, sci_dev, sci_total = 0;
    double eng_ave, eng_dev, eng_total = 0;
    double sci_var, eng_var = 0;
    double sci_dev_value[20];
    double eng_dev_value[20];
    double sci_tmp, eng_tmp;
    int i, j;

    for(i = 0; i < 20; i++){
        sci_total += sci[i];
        eng_total += eng[i];
    }

    sci_ave = sci_total / 20;
    eng_ave = eng_total / 20;

    for(i = 0; i < 20; i++){
        sci_var += (sci[i] - sci_ave) * (sci[i] - sci_ave);
        eng_var += (eng[i] - eng_ave) * (eng[i] - eng_ave);
    }
    sci_dev = sqrt(sci_var / 20);
    eng_dev = sqrt(eng_var / 20);

    for(i = 0; i < 20; i++){
        sci_dev_value[i] = fabs(sci[i] - sci_ave) * 10 / sci_dev;
        eng_dev_value[i] = fabs(eng[i] - eng_ave) * 10 / eng_dev;
    }

    for(i = 0; i < 20; i++){
        for(j = i + 1; j < 20; j++){
            if(sci[i] < sci[j]){
                sci_tmp = sci[i];
                sci[i] = sci[j];
                sci[j] = sci_tmp;
            }
            if(eng[i] < eng[j]){
                eng_tmp = eng[i];
                eng[i] = eng[j];
                eng[j] = eng_tmp;
            }
        }
    }

 printf("[理科]\n");
    printf("平均値:%f 標準偏差:%f 合計点:%f\n", sci_ave, sci_dev, sci_total);
    printf("偏差値:\n");
    for(i = 0; i < 20; i++){
        printf("%f  ", sci_dev_value[i]);
        if((i + 1) % 4 == 0){
            printf("\n");
        }
    }
    printf("\n");
    printf("点数の降順ソート:\n");
    for(i = 0; i < 20; i++){
        printf("%f  ", sci[i]);
        if((i + 1) % 4 == 0){
            printf("\n");
        }
    }
    printf("\n\n");
    printf("[英語]\n");
    printf("平均値:%f 標準偏差:%f 合計点:%f\n", eng_ave, eng_dev, eng_total);
    printf("偏差値:\n");
    for(i = 0; i < 20; i++){
        printf("%f  ", eng_dev_value[i]);
        if((i + 1) % 4 == 0){
            printf("\n");
        }
    }
    printf("\n");
    printf("点数の降順ソート:\n");
    for(i = 0; i < 20; i++){
        printf("%f  ", eng[i]);
        if((i + 1) % 4 == 0){
            printf("\n");
        }
    }

    return 0;
}
