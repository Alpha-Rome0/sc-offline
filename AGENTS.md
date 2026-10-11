# AGENTS.md — sc-offline product charter

Read with CONTRIBUTING.md, sco-core/AGENTS.md and the current submodule pin. sc-offline is the offline game product and bootstrap, not the owner of the general-purpose SDK.

## P0 incident first
v0.7.5 megamap access violation: Game.log for game 4.10.196.36804 reports 0xC0000005 at 0x00007FFB3488FA7D, outside the reported StarCitizen.exe image. Two later mod.log sessions show event.player_death already_hooked, but logs are not from the same session. Resolve crash module/stack and independently audit duplicate hook targets; do not equate these symptoms. Keep private dump/log identifiers out of public issues. Test against the matched version and report in-game verification.

## Architectural rules
1. Product built-ins must consume sco-core's public SDK services; move patch-specific signature ownership, engine internals and reusable services into the optional sco-core game pack. Follow the checked public-header gate, never silently depend on sco-core internal headers.
2. Preserve the frozen sco_api.h v1.1 contract. Follow documented service versioning, opaque IDs, thread affinity, callbacks, game-read-only Lua and deterministic unload/reload cleanup.
3. Pin external/sco-core deliberately; pair upstream changes with downstream build and behavior tests. Do not assert that a CI pass substitutes for actual gameplay validation.
4. Keep behavior offline and within CONTRIBUTING.md; no proprietary game binaries/assets/dumps, DRM or anti-cheat circumvention, official-online features, unapproved connections or sensitive user logs.
5. Fix regressions before feature expansion. Work in small PRs, re-check active PRs and provide proof of test results, known uncertainties and follow-up items.
6. Maintain docs/status.md, tests and changelog with behavior changes. Feed generalized product lessons back to sco-core in the same work cycle.

## SDK declaration readiness
Support sco-core's three-profile release (core ZIP, game-sc ZIP, legacy ZIP) with explicit versions, tested submodule compatibility and required separate checksums/SBOMs. Publication requires human approval. A readiness sign-off means all bounded release-impacting work is completed or explicitly scoped out, not that unbounded future work is done.

External Hermes, cron-bot and OmO agents must adhere to this checked-in charter rather than conflicting copied instructions.
