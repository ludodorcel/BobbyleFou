#ifndef _IRIS_H_
#define _IRIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct sTreeNode treeNode;
typedef struct sFlowerListNode flowerListNode;
typedef struct sList list;


typedef struct sParam
{
    float m_min;
    float m_max;
}param;

struct sList
{
	flowerListNode *		m_head;				          /**< Pointeur sur la t�te de liste										*/
};

typedef struct sFlower
{
	float					m_petalWidth;		          /**< Largeur p�tale (param�tre 3)										*/
	float					m_petalLength;			      /**< Longueur p�tal (param�tre 2)										*/
	float					m_sepalWidth;			      /**< Largeur s�pal (param�tre 1)										*/
	float					m_sepalLength;			      /**< Longueur s�pal (param�tre 0)										*/
	char					m_specieNamed[30];		      /**< Nom de l'�sp�ce (classe)											*/
}flower;

struct sFlowerListNode
{
	flower					m_dataFlower;			      /**< Caract�ristique de la fleur										*/
	flowerListNode *		m_next;					      /**< Pointeur vers le noeud de liste suivant.							*/
};

struct sTreeNode
{
	int						m_valueCompared;		      /**< Valeur de comparaison des param�tre								*/
	param					m_parameterTab[4];			  /**< Tableau des param�tres (voir commentaire de la structure fleur pour l'ordre      */											
	float					m_entropy;				      /**< Entropie du noeud													*/
	int						m_samples;				      /**< Nombre de fleur dans le noeud										*/
	float *					m_tabValue;				      /**< Tableau du nombre de fleurs par �sp�ce									*/

	list *		            m_irisList;				      /**< Liste des fleurs													*/

	treeNode *				m_leftSon;			       	  /**< Noeud fils gauche													*/
    treeNode *				m_rightSon;			    	  /**< Noeud fils droit													*/
};


list * CreateDataList(FILE * p_pfile, list * p_pflowerlist, int p_nbData);

void insererFin(list * p_pflowerList, flower p_dataFlower);

flowerListNode * creerNoeudList(flower p_dataFlower);

int CountNbLignes(FILE * p_pfile);

void afficherList(list * p_pHead);

void NbFlowerBySpecies(treeNode * p_pflowerNode);

treeNode * CreateNode(treeNode * p_pflowerNode);

void InitialisationMinEtMax(treeNode * p_pflowerNode);

float ComparedSepalLength(treeNode * p_pflowerNode);

float * ComparedPetalWidth(treeNode * p_pflowerNode);

float * ComparedPetalLength(treeNode * p_pflowerNode);

float * ComparedSepalWidth(treeNode * p_pflowerNode);



#endif //_IRIS_H_
