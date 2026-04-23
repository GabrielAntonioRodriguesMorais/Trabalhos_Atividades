#include <stdio.h>

int main()
{
    int idade = 0, opniao, op_m = 0, op_f = 0, MI_m = -1, mI_f = -1, totalPessoas = 0, totalPessoas_nao_gostaram = 0;
    float porcentagem;
    char genero;

    do
    {
        scanf("%d", &idade);
        if (idade < 0)
        {
            break;
        }
        scanf(" %c", &genero);
        scanf("%d", &opniao);

        totalPessoas++;

        if (opniao == 1)
        {
            if (genero == 'M')
            {
                op_m++;

                if (MI_m == -1 || idade > MI_m)
                {
                    MI_m = idade;
                }
            }
            else if (genero == 'F')
            {
                op_f++;
            }
        }
        else
        {
            totalPessoas_nao_gostaram++;
            if (genero == 'F')
            {
                if (mI_f == -1 || idade < mI_f)
                {
                    mI_f = idade;
                }
            }
        }
    } while (idade > 0);

    porcentagem = ((totalPessoas_nao_gostaram * 100.0) / totalPessoas);

    printf("Masculino: %d\n", op_m);
    printf("Feminino: %d\n", op_f);
    printf("%d Anos\n", MI_m);
    printf("%d Anos\n", mI_f);
    printf("%.2f%%", porcentagem);
}