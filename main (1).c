#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void inicio() { printf("\nDERIVADAS FUNçÕES POLINOMIAIS\n\n"); }

bool ehTermo() // Ver se tem X ou não no termo
{
  printf("Este termo tem uma variável?[S/N]: ");
  char Resp;
  scanf(" %c", &Resp);
  if (Resp == 'S') {
    return true;
  } else {
    return false;
  }
}
int valorPotencia(int potencia) // Descobrir o valor da potencia de x
{
  do {
    printf("Determine a potência: ");
    scanf("%i", &potencia);
  } while (potencia <= 0);
  return potencia;
}

int termosExp(int termos) // Números de termos da função
{
  printf("Determine quantos termos terá sua função: ");
  scanf("%i", &termos);
  return termos;
}

int valorTermo(int num) // Valor que multiplica cada termo da expressão
{
  do{printf("Digite o valor do termo: ");
  scanf("%i", &num);}while(num==0);
  return num;
}

int SOMAfuncao(int SomaProduto, int termos, char str[], int array[],
               int ARRAY[], int a, int produto) {

  for (int i = 0; i < termos; i++) {
    if (str[i] == 'X') {
      if (ARRAY[i] == 1) {
        produto = array[i] * a;
      } else {
        produto = array[i] * pow(a, ARRAY[i]);
      }
    } else {
      produto = array[i];
    }
    SomaProduto += produto;
  }

  return SomaProduto;
}
int SOMAderivada(int SomaDerivada, int termos, char str[], int array[],
                 int ARRAY[], int a, int produto2) {

  for (int i = 0; i < termos; i++) {
    if (ARRAY[i] == 1) {
      produto2 = array[i] * a;

    } else {
      if (ARRAY[i] > 1) {
        produto2 = array[i] * pow(a, ARRAY[i]);

      } else {
        produto2 = array[i];
      }
    }
    SomaDerivada = SomaDerivada + produto2;
  }

  return SomaDerivada;
}

int main() {
  void inicio();

  int a;
  printf("\nDigite o valor de a caso queira o valor funcional depois: ");
  scanf("%i", &a);
  int termos = termosExp(termos);
  int array[termos]; // array para lozalizar a base
  int num;
  char str[termos];
  int potencia;
  bool temX;
  int c;
  int Z;
  char ValorFunc;
  int produto;
  int SomaProduto = 0;
  int produto2;
  int SomaDerivada = 0;
  char CalcularA; // variavel para ver se o usuario quer ou não calcular o valor
                  // funcional
  int ARRAY[termos];  // array para localizar a potencia
  char CalcEqRetaTan; // quer ou nao calcular a eq reta tangente

  for (int i = 0; i < termos; i++) {
    // leitura dos termos
    num = valorTermo(num);
    array[i] = num;
    temX = ehTermo();
    if (temX == true) {
      str[i] = 'X';
      potencia = valorPotencia(potencia);
      ARRAY[i] = potencia;
    } else {

      str[i] = 'M';
    }
  }
  if (ARRAY[0] == 1 && array[0] == 1) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\nf(x)= %c",
           str[0]);
  } else if (ARRAY[0] > 1 && array[0] != 1) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\nf(x)= %i%c^%i",
           array[0], str[0], ARRAY[0]);
  } else if (ARRAY[0] > 1 && array[0] == 1) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\nf(x)= %c^%i",
           str[0], ARRAY[0]);

  } else if (ARRAY[0] > 1 && array[0] == -1) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\nf(x)= -%c^%i",
           str[0], ARRAY[0]);
  } else if (ARRAY[0] == 1 && array[0] == -1) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           "\n\n\n\nf(x)= -%c",
           str[0]);
  }

  else {
    if (str[0] == 'M')
      printf(
          "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
          "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
          "\n\n\n\nf(x) = %i",
          array[0]);
  }

  for (int c = 1; c < termos; c++) // imprimir expressão
  {

    if (ARRAY[c] > 1) {
      if (array[c] < 0 && array[c] != -1) {
        printf(" %i%c^%i", array[c], str[c], ARRAY[c]);
      } else {
        if (array[c] > 0 && array[c] != 1) {
          printf(" + %i%c^%i", array[c], str[c], ARRAY[c]);
        }

        else {
          if (array[c] == 1) {
            printf(" + %c^%i", str[c], ARRAY[c]);
          } else {
            if (array[c] == -1) {
              printf(" - %c^%i", str[c], ARRAY[c]);
            }
          }
        }
      }

    } else {
      if (ARRAY[c] == 1 && array[c] != 1 && array[c] != -1) {
        printf("+ %i%c", array[c], str[c]);
      } else {
        if (ARRAY[c] == 1 && array[c] == 1) {
          printf("+ %c", str[c]);
        }
      }
      {
        if (ARRAY[c] == 1 && array[c] == -1) {
          printf("- %c", str[c]);
        }
      }
      {
        if (str[c] == 'M' && array[c] > 0) {
          printf(" + %i", array[c]);
        } else {
          if (str[c] == 'M' && array[c] < 0)
            printf(" %i", array[c]);
        }
      }
    }
  }

  SomaProduto = SOMAfuncao(SomaProduto, termos, str, array, ARRAY, a,
                           produto); // funçao para achar f(a)

  if (str[0] == 'M') { // realizar derivada
    printf("\n\nf'(x) = 0");
  } else {
    if (ARRAY[Z] > 1) {
      array[0] = array[0] * ARRAY[0];
      ARRAY[0] = ARRAY[0] - 1;
      if (ARRAY[0] > 1) {
        printf(" \n\nf'(x) = %i%c^%i ", array[0], str[0], ARRAY[0]);
      } else {
        printf("\n\n f'(x) = %i%c ", array[0], str[0]);
      }

    } else {
      printf(" \n\nf'(x)= %i", array[Z]);
    }
  }

  for (Z = 1; Z < termos; Z++) { // realizar derivada

    if (str[Z] == 'M') {
      array[Z] = 0;
      printf("+ 0");
    } else {
      if (ARRAY[Z] > 1) {
        array[Z] = array[Z] * ARRAY[Z];
        ARRAY[Z] = ARRAY[Z] - 1;
        if (ARRAY[Z] > 1) {
          printf(" + %i%c^%i ", array[Z], str[Z], ARRAY[Z]);
        } else {
          printf("  %i%c ", array[Z], str[Z]);
        }

      } else {
        printf(" + %i", array[Z]);
      }
    }
  }
  SomaDerivada = SOMAderivada(SomaDerivada, termos, str, array, ARRAY, a,
                              produto2); // funçao para achar f'(a)

  printf("\nDeseja calcular o valor funcional[S/N]? ");
  scanf(" %c", &ValorFunc);
  if (ValorFunc == 'S') {
    printf("\n a = %i", a);
    printf("\n\nf(%i)= %i", a, SomaProduto);
    printf("\n\nf'(%i) = %i", a, SomaDerivada);
    printf("\n\nP(%i,%i)", a, SomaProduto);

    printf("\n\nDeseja calcular a equação da reta tangente ao gráfico de f "
           "no ponto P(a, f(a)?[S/N]: ");
    scanf(" %c", &CalcEqRetaTan);
    int b;
    if (CalcEqRetaTan == 'S') {
      b = SomaProduto - SomaDerivada;
      if (SomaDerivada == 1) {
        printf("y = X +(%i)", b);
      }
      if (SomaDerivada == -1) {
        printf("y = -X +(%i)", b);
      } else {
        printf("A equação da reta tangente é y = %iX +(%i)", SomaDerivada, b);
      }
    }
  } else {
    printf("\nFim do programa");
  }

  return 0;
}
