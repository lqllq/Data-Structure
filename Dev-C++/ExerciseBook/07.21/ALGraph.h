/*==================
 * ͼ���ڽӱ��洢��ʾ
 ===================*/

#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <stdio.h>
#include <string.h>     // �ṩmemset��strcmp ԭ��
#include <stdarg.h>     // �ṩ��va_list��va_start��va_arg��va_end
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/*
 * ע��
 *
 * ͨ����������Ȩͼ�����Ϊ��ͼ������Ȩͼ�����Ϊ��������
 * ����ͼ/���еĶ����ϵ����Ϊ���ߡ�������ͼ/���еĶ����ϵ����Ϊ�������������ֻ�ͷ�뻡β��
 * ʵ�ʱ����У�δ�ػ��ϸ���������������
 *
 * ��ǰ�ṹ�ʺϴ洢��/���Ƚ�ϡ���ͼ/����
 *
 * �� �����/������Ϣʱ�������ʵ���ǰ�"����"����ģ���ʹ�ò���Ļ��ǰ�"����"���еġ�
 */


/* �궨�� */
#define MAX_VERTEX_NUM 26   // ��󶥵����


// ͼ������
typedef enum {
    DG,     // 0-����ͼ
    DN,     // 1-������(��Ȩֵ)
    UDG,    // 2-����ͼ
    UDN     // 3-������(��Ȩֵ)
} GraphKind;

// ��������
typedef char VertexType;

// ��/������ظ�����Ϣ
typedef struct {
    /*
     * ע��
     * �̲��и����Ľṹֻ��������Ȩͼ����û������Ȩͼ(��)��
     * ����Ϊ�˰ѡ�����������Ҳ���ǽ�ȥ�����ڸ�����Ϣ��������"Ȩ��"���ԡ�
     */
    int weight;
} InfoType;

/* ��/����� */
typedef struct ArcNode {
    int adjvex;                 // �û���ָ��Ķ����λ��
    struct ArcNode* nextarc;    // ָ����һ������ָ��
    InfoType* info;             // ���ĸ�����Ϣ��ͨ������
} ArcNode;

// ÿ��������ͷ���
typedef struct VNode {
    VertexType data;    // ������Ϣ
    ArcNode* firstarc;  // ָ���һ�������ö���Ļ���ָ��
} VNode;

/* ͼ���ڽӱ��洢��ʾ���Ͷ��� */
typedef struct {
    VNode vertices[MAX_VERTEX_NUM]; // �ڽӱ�
    int vexnum, arcnum;             // ͼ/���Ķ������ͻ���
    GraphKind kind;                 // ͼ�����ͱ�־
} ALGraph;


// ��/�����Ƿ���ڸ�����Ϣ
extern Boolean IncInfo;


/*
 * ����
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����path[kind]Ϊ""��
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateGraph(ALGraph* G, char* path[]);

/*
 * ��������ͼ
 */
static Status CreateDG(ALGraph* G);

/*
 * ����������
 */
static Status CreateDN(ALGraph* G);

/*
 * ��������ͼ
 */
static Status CreateUDG(ALGraph* G);

/*
 * ����������
 */
static Status CreateUDN(ALGraph* G);

/*
 * ¼���/������ظ�����Ϣ
 */
static void Input(ALGraph G, InfoType** info);

/*
 * ����
 *
 * ���ض���u��ͼ/���е�λ��
 */
int LocateVex(ALGraph G, VertexType u);

/*
 * ����һ����/�����(�����ڲ�ʹ��)
 */
static ArcNode* newArcNodePtr(int adjvex, ArcNode* nextarc, InfoType* info);

/*
 * �����/��<v, w>
 *
 * �����ǰͼ/��������ģ������һ������Ҫ�������������ϵ������������ֻ��һ��
 * ����ͼ/����˵�������ڿɱ�������г���/���ĸ�����Ϣ��
 *
 * ע���˴����յĲ�����MGraph��Щ��һ�������ĸ�����Ϣ�а����˸�����/����Ȩֵ��
 */
Status InsertArc(ALGraph* G, VertexType v, VertexType w, ...);

/*
 * ��ͼ�λ���ʽ�����ǰ�ṹ
 */
void PrintGraph(ALGraph G);

#endif