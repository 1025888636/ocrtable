#pragma once
#ifndef TABLEOCR_API
	#define TABLEOCR_API extern "C" __declspec(dllimport)
#endif

// ѡ������
typedef struct _TOOPTION
{
	BOOL isMerged;	// �Ƿ�����ϲ��ĵ�Ԫ���������ȷ������ΪTRUE
	int minSize;	// ��С�и�
	int threshold;	// Hough������ֵ,������Ϊ5-10
	int delta;		// �����߿���б��������������ʱ�ݴ�����ط�Χ��������Ϊ3
}TOOPTION;

/*
����ͼƬ����ʼ����
����˵����
pszImagePath	[in, string] ͼƬ·��
pOption			[in] ѡ������
pSize			[out] ����ͼƬ�Ĵ�С
����ֵ��
OCR���������þ��ʹ����Ϻ�ͨ��TOFree�����ͷš����ʧ�ܣ�����NULL��
*/
TABLEOCR_API void* WINAPI TOLoadImage(const char* pszImagePath, const TOOPTION* pOption, LPSIZE pSize);

/*
�ͷ�OCR��������
����˵����
hTO				[in, out] TOLoadImage���ص�OCR������
*/
TABLEOCR_API void WINAPI TOFree(void* hTO);

/*
��ȡͼƬ�б���������
����˵����
hTO				[in, out] TOLoadImage���ص�OCR������
����ֵ��
����������
*/
TABLEOCR_API int WINAPI TOGetTableCount(void* hTO);

/*
����������ȡ���
����˵����
hTO				[in, out] TOLoadImage���ص�OCR������
index			[in] �����ͼƬ�е���������0��ʼ
pRect			[out] �����ͼƬ�е�λ�úʹ�С
����ֵ��
���ľ�����þ������Ҫ�ͷš�
*/
TABLEOCR_API void* WINAPI TOGetTable(void* hTO, int index, LPRECT pRect);

/*
��ȡ����������
����˵����
hTable			[in, out] TOGetTable���صı����
����ֵ��
����������
*/
TABLEOCR_API int WINAPI TOGetRowCount(void* hTable);

/*
��ȡ����������
����˵����
hTable			[in, out] TOGetTable���صı����
����ֵ��
����������
*/
TABLEOCR_API int WINAPI TOGetColumnCount(void* hTable);

/*
��ȡ���ָ���е��иߡ�
����˵����
hTable			[in, out] TOGetTable���صı����
iRow			[in] �е���������0��ʼ
����ֵ��
���е��иߡ�
*/
TABLEOCR_API int WINAPI TOGetRowHeight(void* hTable, int iRow);

/*
��ȡ���ָ���е��п�
����˵����
hTable			[in, out] TOGetTable���صı����
iCol			[in] �е���������0��ʼ
����ֵ��
���е��п�
*/
TABLEOCR_API int WINAPI TOGetColumnWidth(void* hTable, int iCol);

/*
��ȡ��Ԫ���λ�úʹ�С��
����˵����
hTable			[in, out] TOGetTable���صı����
iRow			[in] �е���������0��ʼ���Ҳ��������е�Ԫ��ϲ���Ӱ��
iCol			[in] �е���������0��ʼ���Ҳ��������е�Ԫ��ϲ���Ӱ��
pRect			[out] ���յ�Ԫ���λ�úʹ�С�������Ԫ�񱻺ϲ������ص��Ǻϲ����λ�úʹ�С
����ֵ��
�����Ԫ��δ���ϲ�������TRUE����������Ԫ��ϲ�����������ϵĵ�Ԫ�񷵻�TRUE��������Ԫ�񷵻�FALSE��
*/
TABLEOCR_API BOOL WINAPI TOGetCell(void* hTable, int iRow, int iCol, LPRECT pRect);

/*
����OpenCV�Ӵ���ʾʶ��ı��ͨ�����ڵ��ԡ�
����˵����
hTable			[in, out] TOGetTable���صı����
winname			[in, string] �������֣����Ҫ��ʾ������ڣ�Ӧʹ�ò�ͬ����
ratio			[in] ͼ����С������1��ʾ����
*/
TABLEOCR_API void WINAPI TODrawTable(void* hTable, const char* winname, int ratio);

/*
ʶ��ָ����������֡�
����˵����
hTO				[in, out] TOLoadImage���ص�OCR������
pRect			[in] �����λ�úʹ�С
����ֵ��
ʶ����ַ��������ַ������������´ε���TOOcrǰ��Ч��
*/
TABLEOCR_API const char* WINAPI TOOcr(void* hTO, const RECT* pRect);