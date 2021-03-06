// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_CHILD_GEOFENCING_WEB_GEOFENCING_PROVIDER_IMPL_H_
#define CONTENT_CHILD_GEOFENCING_WEB_GEOFENCING_PROVIDER_IMPL_H_

#include "base/compiler_specific.h"
#include "base/memory/ref_counted.h"
#include "third_party/WebKit/public/platform/WebGeofencingProvider.h"

namespace content {
class GeofencingDispatcher;
class ThreadSafeSender;

class WebGeofencingProviderImpl
    : NON_EXPORTED_BASE(public blink::WebGeofencingProvider) {
 public:
  explicit WebGeofencingProviderImpl(ThreadSafeSender* thread_safe_sender);
  virtual ~WebGeofencingProviderImpl();

 private:
  // WebGeofencingProvider implementation.
  virtual void registerRegion(
      const blink::WebString& regionId,
      const blink::WebCircularGeofencingRegion& region,
      blink::WebServiceWorkerRegistration* service_worker_registration,
      blink::WebGeofencingCallbacks* callbacks);
  virtual void unregisterRegion(
      const blink::WebString& regionId,
      blink::WebServiceWorkerRegistration* service_worker_registration,
      blink::WebGeofencingCallbacks* callbacks);
  virtual void getRegisteredRegions(
      blink::WebServiceWorkerRegistration* service_worker_registration,
      blink::WebGeofencingRegionsCallbacks* callbacks);

  GeofencingDispatcher* GetDispatcher();

  scoped_refptr<ThreadSafeSender> thread_safe_sender_;

  DISALLOW_COPY_AND_ASSIGN(WebGeofencingProviderImpl);
};

}  // namespace content

#endif  // CONTENT_CHILD_GEOFENCING_WEB_GEOFENCING_PROVIDER_IMPL_H_
