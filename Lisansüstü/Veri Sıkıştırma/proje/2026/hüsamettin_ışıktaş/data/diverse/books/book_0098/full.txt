# Copyright (c) 2022 Tulir Asokan
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
from typing import Dict, List, NamedTuple, Optional, Union
from enum import IntEnum
import re

from attr import dataclass
import attr

from . import JSON
from .util import Serializable, SerializableAttrs


class VersionFormat(IntEnum):
    UNKNOWN = -1
    LEGACY = 0
    MODERN = 1

    def __repr__(self) -> str:
        return f"VersionFormat.{self.name}"


legacy_version_regex = re.compile(r"^r(\d+)\.(\d+)\.(\d+)$")
modern_version_regex = re.compile(r"^v(\d+)\.(\d+)$")


@attr.dataclass(frozen=True)
class Version(Serializable):
    format: VersionFormat
    major: int
    minor: int
    patch: int
    raw: str

    def __str__(self) -> str:
        if self.format == VersionFormat.MODERN:
            return f"v{self.major}.{self.minor}"
        elif self.format == VersionFormat.LEGACY:
            return f"r{self.major}.{self.minor}.{self.patch}"
        else:
            return self.raw

    def serialize(self) -> JSON:
        return str(self)

    @classmethod
    def deserialize(cls, raw: JSON) -> "Version":
        assert isinstance(raw, str), "versions must be strings"
        if modern := modern_version_regex.fullmatch(raw):
            major, minor = modern.groups()
            return Version(VersionFormat.MODERN, int(major), int(minor), 0, raw)
        elif legacy := legacy_version_regex.fullmatch(raw):
            major, minor, patch = legacy.groups()
            return Version(VersionFormat.LEGACY, int(major), int(minor), int(patch), raw)
        else:
            return Version(VersionFormat.UNKNOWN, 0, 0, 0, raw)


class SpecVersions:
    R010 = Version.deserialize("r0.1.0")
    R020 = Version.deserialize("r0.2.0")
    R030 = Version.deserialize("r0.3.0")
    R040 = Version.deserialize("r0.4.0")
    R050 = Version.deserialize("r0.5.0")
    R060 = Version.deserialize("r0.6.0")
    R061 = Version.deserialize("r0.6.1")
    V11 = Version.deserialize("v1.1")
    V12 = Version.deserialize("v1.2")
    V13 = Version.deserialize("v1.3")
    V14 = Version.deserialize("v1.4")
    V15 = Version.deserialize("v1.5")
    V16 = Version.deserialize("v1.6")
    V17 = Version.deserialize("v1.7")
    V18 = Version.deserialize("v1.8")
    V19 = Version.deserialize("v1.9")
    V110 = Version.deserialize("v1.10")
    V111 = Version.deserialize("v1.11")


@dataclass
class VersionsResponse(SerializableAttrs):
    versions: List[Version]
    unstable_features: Dict[str, bool] = attr.ib(factory=lambda: {})

    def supports(self, thing: Union[Version, str]) -> Optional[bool]:
        """
        Check if the versions response contains the given spec version or unstable feature.

        Args:
            thing: The spec version (as a :class:`Version` or string)
                   or unstable feature name (as a string) to check.

        Returns:
            ``True`` if the exact version or unstable feature is supported,
            ``False`` if it's not supported,
            ``None`` for unstable features which are not included in the response at all.
        """
        if isinstance(thing, Version):
            return thing in self.versions
        elif (parsed_version := Version.deserialize(thing)).format != VersionFormat.UNKNOWN:
            return parsed_version in self.versions
        return self.unstable_features.get(thing)

    def supports_at_least(self, version: Union[Version, str]) -> bool:
        """
        Check if the versions response contains the given spec version or any higher version.

        Args:
            version: The spec version as a :class:`Version` or a string.

        Returns:
            ``True`` if a version equal to or higher than the given version is found,
            ``False`` otherwise.
        """
        if isinstance(version, str):
            version = Version.deserialize(version)
        return any(v for v in self.versions if v > version)

    @property
    def latest_version(self) -> Version:
        return max(self.versions)

    @property
    def has_legacy_versions(self) -> bool:
        """
        Check if the response contains any legacy (r0.x.y) versions.

        .. deprecated:: 0.16.10
           :meth:`supports_at_least` and :meth:`supports` methods are now preferred.
        """
        return any(v for v in self.versions if v.format == VersionFormat.LEGACY)

    @property
    def has_modern_versions(self) -> bool:
        """
        Check if the response contains any modern (v1.1 or higher) versions.

        .. deprecated:: 0.16.10
           :meth:`supports_at_least` and :meth:`supports` methods are now preferred.
        """
        return self.supports_at_least(SpecVersions.V11)
