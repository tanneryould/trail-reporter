// Copyright 2022 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "TrailReporter.h"

#include "Basemap.h"
#include "Map.h"
#include "MapQuickView.h"

#include <QUrl>

using namespace Esri::ArcGISRuntime;

TrailReporter::TrailReporter(QObject* parent /* = nullptr */):
  QObject(parent),
  m_map(new Map(BasemapStyle::ArcGISTopographic, this))
{
}

TrailReporter::~TrailReporter()
{
}

MapQuickView* TrailReporter::mapView() const
{
  return m_mapView;
}

// Set the view (created in QML)
void TrailReporter::setMapView(MapQuickView* mapView)
{
  if (!mapView || mapView == m_mapView)
  {
    return;
  }

  m_mapView = mapView;
  m_mapView->setMap(m_map);

  emit mapViewChanged();
}
