#include "Mesh.h"
#include "imgui/imgui.h"
#include <unordered_map>
#include <sstream>
#include "Surface.h"
#include <filesystem>
#include "SudalXM.h"
#include "DynamicConstant.h"
#include "ConstantBuffersEX.h"
#include "LayoutCodex.h"
#include "Stencil.h"


namespace dx = DirectX;



// Mesh
Mesh::Mesh(Graphics& gfx, const Material& mat, const aiMesh& mesh, float scale) noxnd
	:
	Drawable(gfx, mat, mesh, scale)
{}

void Mesh::Submit(FrameCommander& frame, dx::FXMMATRIX accumulatedTranform) const noxnd
{
	dx::XMStoreFloat4x4(&transform, accumulatedTranform);
	Drawable::Submit(frame);
}

DirectX::XMMATRIX Mesh::GetTransformXM() const noexcept
{
	return DirectX::XMLoadFloat4x4(&transform);
}