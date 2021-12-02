/*==============================================================================

   ���_�Ǘ� [polygon.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "map_line.h"
#include "map.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define NUM_VERTEX 12	//�K�v�Ȓ��_�̐�

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
void SetVertex(void);
//float frand(void);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;		// ���_���

struct VERTEX_T {
	D3DXVECTOR2		pos;	//�ʒu�x�N�g��
	D3DXCOLOR		color;	//���_�J���[
};

static VERTEX_T g_Vertex[NUM_VERTEX];


//=============================================================================
// ����������
//=============================================================================
HRESULT InitPolygon(void)
{
	//ID3D11Device* pDevice = GetDevice();

	//// ���_�o�b�t�@����
	//D3D11_BUFFER_DESC bd;
	//ZeroMemory(&bd, sizeof(bd));
	//bd.Usage = D3D11_USAGE_DYNAMIC;
	//bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX;
	//bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	//bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	//GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBuffer);

	//MAP* map = GetMap();

	////������
	//for (int i = 0; i < NUM_VERTEX; i++)
	//{
	//	g_Vertex[0].pos.x = map[0].pos.x + map[0].size.x * 0.5f;
	//	g_Vertex[0].pos.y = map[0].pos.y + map[0].size.y * 0.5f;
	//	g_Vertex[1].pos.x = map[1].pos.x + map[1].size.x * 0.5f;
	//	g_Vertex[1].pos.y = map[1].pos.y + map[1].size.y * 0.5f;

	//	g_Vertex[2].pos.x = map[0].pos.x + map[0].size.x * 0.5f;
	//	g_Vertex[2].pos.y = map[0].pos.y + map[0].size.y * 0.5f;
	//	g_Vertex[3].pos.x = map[2].pos.x + map[2].size.x * 0.5f;
	//	g_Vertex[3].pos.y = map[2].pos.y + map[2].size.y * 0.5f;

	//	g_Vertex[4].pos.x = map[0].pos.x + map[0].size.x * 0.5f;
	//	g_Vertex[4].pos.y = map[0].pos.y + map[0].size.y * 0.5f;
	//	g_Vertex[5].pos.x = map[3].pos.x + map[3].size.x * 0.5f;
	//	g_Vertex[5].pos.y = map[3].pos.y + map[3].size.y * 0.5f;

	//	g_Vertex[i].color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//}

	//// ���_�o�b�t�@�X�V
	//SetVertex();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitPolygon(void)
{
	//// ���_�o�b�t�@�̉��
	//if (g_VertexBuffer)
	//{
	//	g_VertexBuffer->Release();
	//	g_VertexBuffer = NULL;
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdatePolygon(void)
{

}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawPolygon(void)
{
	//// ���_�o�b�t�@�ݒ�
	//UINT stride = sizeof(VERTEX_3D);
	//UINT offset = 0;
	//GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	//// �}�g���N�X�ݒ�
	//SetWorldViewProjection2D();//���W��2D�ϊ�

	//// �v���~�e�B�u�g�|���W�ݒ�
	//GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	//// �}�e���A���ݒ�i���N��Ɍ����j
	//MATERIAL material;
	//ZeroMemory(&material, sizeof(material));
	//material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//SetMaterial(material);

	//SetVertex();

	//// �|���S���`��
	//GetDeviceContext()->Draw(NUM_VERTEX, 0);
}


//=============================================================================
// ���_�f�[�^�ݒ�
//=============================================================================
void SetVertex(void)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	//���_�o�b�t�@�̃f�[�^���X�V����
	for (int i = 0; i < NUM_VERTEX; i++)
	{
		vertex[i].Position = D3DXVECTOR3(g_Vertex[i].pos.x, g_Vertex[i].pos.y, 0.0f);
		vertex[i].Diffuse = g_Vertex[i].color;
	}

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);
}


//0.0�@�`�@1.0�̃����_���Ȓl���擾����
//float frand(void)
//{
//	return (float)rand() / RAND_MAX;
//}
