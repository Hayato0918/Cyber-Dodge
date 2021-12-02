/*==============================================================================

   頂点管理 [polygon.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "map_line.h"
#include "map.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define NUM_VERTEX 12	//必要な頂点の数

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
void SetVertex(void);
//float frand(void);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static ID3D11Buffer* g_VertexBuffer = NULL;		// 頂点情報

struct VERTEX_T {
	D3DXVECTOR2		pos;	//位置ベクトル
	D3DXCOLOR		color;	//頂点カラー
};

static VERTEX_T g_Vertex[NUM_VERTEX];


//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitPolygon(void)
{
	//ID3D11Device* pDevice = GetDevice();

	//// 頂点バッファ生成
	//D3D11_BUFFER_DESC bd;
	//ZeroMemory(&bd, sizeof(bd));
	//bd.Usage = D3D11_USAGE_DYNAMIC;
	//bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX;
	//bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	//bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	//GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBuffer);

	//MAP* map = GetMap();

	////初期化
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

	//// 頂点バッファ更新
	//SetVertex();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitPolygon(void)
{
	//// 頂点バッファの解放
	//if (g_VertexBuffer)
	//{
	//	g_VertexBuffer->Release();
	//	g_VertexBuffer = NULL;
	//}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdatePolygon(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
void DrawPolygon(void)
{
	//// 頂点バッファ設定
	//UINT stride = sizeof(VERTEX_3D);
	//UINT offset = 0;
	//GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	//// マトリクス設定
	//SetWorldViewProjection2D();//座標の2D変換

	//// プリミティブトポロジ設定
	//GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	//// マテリアル設定（半年後に現れる）
	//MATERIAL material;
	//ZeroMemory(&material, sizeof(material));
	//material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//SetMaterial(material);

	//SetVertex();

	//// ポリゴン描画
	//GetDeviceContext()->Draw(NUM_VERTEX, 0);
}


//=============================================================================
// 頂点データ設定
//=============================================================================
void SetVertex(void)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	//頂点バッファのデータを更新する
	for (int i = 0; i < NUM_VERTEX; i++)
	{
		vertex[i].Position = D3DXVECTOR3(g_Vertex[i].pos.x, g_Vertex[i].pos.y, 0.0f);
		vertex[i].Diffuse = g_Vertex[i].color;
	}

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);
}


//0.0　～　1.0のランダムな値を取得する
//float frand(void)
//{
//	return (float)rand() / RAND_MAX;
//}
