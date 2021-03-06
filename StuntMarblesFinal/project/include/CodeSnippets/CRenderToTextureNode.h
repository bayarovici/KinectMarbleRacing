#ifndef _C_RENDER_TO_TEXTURE_NODE
  #define _C_RENDER_TO_TEXTURE_NODE

  #include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

const int RTT_NODE_ID=MAKE_IRR_ID('c','r','t','t');
const c8 RTT_NODE_NAME[0xFF]="RenderToTextureNode";

/**
 * @class CRespawnNode
 * This is a little helper to define respawn nodes from within IrrEdit. Is also used to identify checkpoints in "Stunt Marble Racers"
 * @author Christian Keimel / dustbin::games
 */
class CRenderToTextureNode : public ISceneNode {
  private:
	ISceneManager *m_pSceneManager;

	u32 m_iMaterial,
		m_iTexture;

	SMaterial m_cMat;             /**< the material of the node */
    #ifdef _IRREDIT_PLUGIN
      IAnimatedMesh *m_pMesh;				/**< the mesh to be renderer in IrrEdit when compiled as plugin */
  	  c8 m_sResources[1024];				/**< the path name of the resources when copiled as plugin */
			IVideoDriver *m_pVideoDriver; /**< the video driver */
    #endif
  public:
    CRenderToTextureNode(ISceneNode *pParent, ISceneManager *pMgr, s32 iId=-1, const vector3df pos=vector3df(0,0,0), const vector3df rot=vector3df(0,0,0), const vector3df scale=vector3df(1,1,1));

    virtual void render();

    virtual const aabbox3df &getBoundingBox() const {
      static aabbox3df aBox;
      return aBox;
    }

    virtual ESCENE_NODE_TYPE getType() const;

    virtual void serializeAttributes(IAttributes* out, SAttributeReadWriteOptions* options) const;
    virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options);

		virtual ISceneNode *clone(ISceneNode* newParent=0, ISceneManager* newManager=0);
    virtual u32 getMaterialCount();
    virtual SMaterial &getMaterial(u32 iIdx);
	virtual void setPosition(const core::vector3df &newpos);
		virtual void OnRegisterSceneNode();

		void setTexture(u32 iTexture) { m_iTexture=iTexture; }
		void setMaterial(u32 iMaterial) { m_iMaterial=iMaterial; }

		u32 getTexture() { return m_iTexture; }
		u32 getMaterial() { return m_iMaterial; }
};

#endif
