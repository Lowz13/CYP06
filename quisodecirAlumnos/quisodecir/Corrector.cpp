/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ponga su nombre y numero de cuenta aqui.
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/
#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#define dep 1
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{
	char auxiliar[60];
	char inter[200];//intermediario de la linea
	char linea[4000];//captura el archivo
	iNumElementos = 0;//numero de palabras en el archivo
	int i = 0, indi, aux, j, k, doom; //acumulador, indice de linea, auxiliar de i
	FILE* fpDicc;//abrir archivo
	fopen_s(&fpDicc, szNombre, "r");
	if (fpDicc != NULL)
	{
		while (!feof(fpDicc))
		{
			fgets(linea, sizeof(linea), fpDicc);//capturar linea de archivo
			_strlwr_s(linea, sizeof(linea));//convertir en minusculas
			indi = 0;
			while (linea[i] != '\0')
			{
				aux = i;
				if (linea[i] != ' ' && linea[i] != ',' && linea[i] != '.' && linea[i] != ';' && linea[i] != ':' && linea[i] != '(' && linea[i] != ')')
				{
					inter[indi] = linea[i];
					indi++;
				}
				else
				{
					if (linea[aux + 1] == '\0')
					{
						inter[indi] = '\0';
						strcpy_s(szPalabras[iNumElementos], TAMTOKEN, inter);
						iEstadisticas[iNumElementos] = 1;
						iNumElementos++;
					}
					if (linea[i] == ' ')
					{
						if (linea[aux + 1] == ' ')
						{
							inter[indi] = '\0';
						}
						else
						{
							inter[indi] = '\0';
							strcpy_s(szPalabras[iNumElementos], TAMTOKEN, inter);
							iEstadisticas[iNumElementos] = 1;
							iNumElementos++;
							indi = 0;
						}
					}
					else
					{
						inter[indi] = '\0';
					}
				}
				i++;
			}
		}
		fclose(fpDicc);
	}
	else
	{
		if (dep == 1)
			printf("\nno abre\n");

	}
	doom = iNumElementos;
	if (dep == 1)
		//ordenar
		for (j = 0; j <= iNumElementos; j++)
		{
			for (k = 0; k < iNumElementos; k++)
			{
				if (j != k)
				{
					if (strcmp(szPalabras[k], szPalabras[k + 1]) == 1)
					{
						strcpy_s(auxiliar, TAMTOKEN, szPalabras[k + 1]);
						strcpy_s(szPalabras[k + 1], TAMTOKEN, szPalabras[k]);
						strcpy_s(szPalabras[k], TAMTOKEN, auxiliar);
					}
				}
			}
		}
	//estadisticas
	if (dep == 1)
		for (j = 0; j < iNumElementos; j++)
		{
			for (k = 0; k < iNumElementos; k++)
			{
				if (j != k && iEstadisticas[k] != 0)
				{
					if (strcmp(szPalabras[j], szPalabras[k]) == 0)
					{
						szPalabras[k][0] = NULL;
						iEstadisticas[j]++;
						iEstadisticas[k] = NULL;
						doom--;
					}
				}

			}

		}
	if (dep == 1)
		for (j = 0; j < iNumElementos/2; j++)
		{
			for (k = 0; k < iNumElementos; k++)
			{
				if (iEstadisticas[k] == 0 && iEstadisticas[k + 1] != 0)
				{
					iEstadisticas[k] = iEstadisticas[k + 1];
					iEstadisticas[k + 1] = 0;
					strcpy_s(szPalabras[k], TAMTOKEN, szPalabras[k + 1]);
					szPalabras[k+1][0] = '\0';
				}

			}
		}
	iNumElementos = doom;
}
/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void	ListaCandidatas		(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
{
	
	//Sustituya estas lineas por su código
	strcpy_s(szListaFinal[0],TAMTOKEN, szPalabrasSugeridas[ 0]); //la palabra candidata
	iPeso[0] = iEstadisticas[0];			// el peso de la palabra candidata
	
	iNumLista = 1;							//Una sola palabra candidata
}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void	ClonaPalabras(
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
{
	//Sustituya estas lineas por su código
	strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
	iNumSugeridas = 1;							//Una sola palabra sugerida
}
