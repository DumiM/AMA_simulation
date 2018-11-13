# AMA Simulation

### Software Context

The software is a simulation for games that reproduces the behaviour of intelligent, autonomously moving agents that is able to successfully mimic biological movement. This is targeted at other games developers to be reused in their development projects to ease the production of intelligent agent systems and/or for researchers trying to understand computer simulations of nature.
##### Scope

An autonomously moving agent can be defined as:
>a system situated within and a part of an environment that senses that environment and  acts on it, over time, in pursuit of its own agendas and so as to effect what it senses in the future.
(Buckland, M. (2004). Programming game AI by example. Jones & Bartlett Learning.)

The simulation will include moving agents, that can seek, flee, arrive, pursuit, evade and wander, together with obstacle avoidance/collision detection. Multiple agents should be able to group together to form convincing “flocking” or “emergent” behaviour patterns. Different roles for these agents should also exist, such as predator/attacker and prey roles.

**Constraints**: Development has been done through C++, and SDL2 (Simple DirectMedia Layer ) for graphics rendering on a 2D level.