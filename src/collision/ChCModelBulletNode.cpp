//
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2010 Alessandro Tasora
// Copyright (c) 2013 Project Chrono
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file at the top level of the distribution
// and at http://projectchrono.org/license-chrono.txt.
//

//////////////////////////////////////////////////
//
//   ChCModelBulletNode.cpp
//
// ------------------------------------------------
//             www.deltaknowledge.com
// ------------------------------------------------
///////////////////////////////////////////////////

#include "ChCModelBulletNode.h"
#include "physics/ChIndexedNodes.h"
#include "physics/ChNodeXYZ.h"
#include "collision/bullet/btBulletCollisionCommon.h"

namespace chrono {
namespace collision {

ChModelBulletNode::ChModelBulletNode() {
    this->nodes = 0;
    this->node_id = 0;
}

ChModelBulletNode::~ChModelBulletNode() {
}

void ChModelBulletNode::SetNode(ChIndexedNodes* mpa, unsigned int id) {
    this->nodes = mpa;
    this->node_id = id;
}

void ChModelBulletNode::SyncPosition() {
    assert(nodes);

    // downcast
    ChSharedPtr<ChNodeXYZ> ppointer(nodes->GetNode(this->node_id).DynamicCastTo<ChNodeXYZ>());
    if (ppointer.IsNull())
        return;

    assert(ppointer);
    assert(nodes->GetSystem());

    bt_collision_object->getWorldTransform().setOrigin(
        btVector3((btScalar)ppointer->GetPos().x, (btScalar)ppointer->GetPos().y, (btScalar)ppointer->GetPos().z));

    btMatrix3x3 basisA((btScalar)1, (btScalar)0, (btScalar)0, (btScalar)0, (btScalar)1, (btScalar)0, (btScalar)0,
                       (btScalar)0, (btScalar)1);  //**rotation does not matter**
    bt_collision_object->getWorldTransform().setBasis(basisA);
}

bool ChModelBulletNode::SetSphereRadius(double coll_radius, double out_envelope) {
    if (this->shapes.size() != 1)
        return false;
    if (btSphereShape* mshape = dynamic_cast<btSphereShape*>(this->shapes[0].get_ptr())) {
        this->SetSafeMargin(coll_radius);
        this->SetEnvelope(out_envelope);
        mshape->setUnscaledRadius((btScalar)(coll_radius + out_envelope));
        // mshape->setMargin((btScalar) (coll_radius+out_envelope));
    } else
        return false;
    return true;
}

}  // END_OF_NAMESPACE____
}  // END_OF_NAMESPACE____
