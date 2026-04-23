#include <stdio.h>

int main()
{
    int voto, votos1 = 0, votos2 = 0, votos3 = 0, votos4 = 0, votosN = 0, votosB = 0;
    float porcentagem, totalVotos = 0.0;

    do
    {
        scanf("%d", &voto);
        if (voto == 1)
        {
            votos1++;
        }
        else if (voto == 2)
        {
            votos2++;
        }
        else if (voto == 3)
        {
            votos3++;
        }
        else if (voto == 4)
        {
            votos4++;
        }
        else if (voto == 5)
        {
            votosN++;
        }
        else if (voto == 6)
        {
            votosB++;
        }
        totalVotos++;

    } while (voto != 0);

    totalVotos--;
    porcentagem = (votosB / totalVotos) * 100.0;
    ;

    printf("Candidato 1: %d voto(s)\n", votos1);
    printf("Candidato 2: %d voto(s)\n", votos2);
    printf("Candidato 3: %d voto(s)\n", votos3);
    printf("Candidato 4: %d voto(s)\n", votos4);
    printf("Votos Nulos: %d \n", votosN);
    printf("Porcentagem de votos em branco: %.2f%%", porcentagem);
}
