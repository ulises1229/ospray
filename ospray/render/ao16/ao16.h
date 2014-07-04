#pragma once

/*! \defgroup ospray_render_ao16 Simple 16-sample Ambient Occlusion Renderer
  
  \ingroup ospray_supported_renderers

  \brief Implements a simple renderer that shoots 16 rays (generated
  using a hard-coded set of random numbers) to compute a trivially
  simple and coarse ambient occlusion effect.

  This renderer is intentionally
  simple, and not very sophisticated (e.g., it does not do any
  post-filtering to reduce noise, nor even try and consider
  transparency, material type, etc.

*/

// ospray
#include "ospray/render/renderer.h"

namespace ospray {
  using embree::TaskScheduler;

  struct Camera;
  struct Model;

  /*! \brief Simple 16-sample Ambient Occlusion Renderer */
  struct AO16Renderer : public Renderer {
    AO16Renderer() : model(NULL), camera(NULL) {};

    virtual std::string toString() const { return "ospray::AO16Renderer"; }

    Model  *model;
    Camera *camera;

    virtual void commit();
  };
};