/*  SPDX-License-Identifier: GPL-2.0-or-later */
/*!********************************************************************

  Audacity: A Digital Audio Editor

  CloudProjectUtils.h

  Dmitry Vedenko

**********************************************************************/
#pragma once

#include <functional>
#include <string_view>

class AudacityProject;

namespace audacity::cloud::audiocom::sync
{
class UploadUrls;
enum class MixdownState : uint32_t;

void OpenProjectFromCloud(
   AudacityProject* potentialTarget, std::string_view projectId,
   std::string_view snapshotId, bool forceNew);

bool SyncCloudProject(
   AudacityProject& project, std::string_view path, bool force = false);

bool HandleProjectLink(std::string_view link);

void UploadMixdown(
   AudacityProject& project,
   std::function<void(AudacityProject&, MixdownState)> onComplete);

void ReopenProject(AudacityProject& project);
} // namespace audacity::cloud::audiocom::sync
