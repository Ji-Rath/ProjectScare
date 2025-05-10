# Project Scare
Small project I've been working on. While it is planned to be a complete game in the near future, its primary use is to let me experiment freely with new systems
on an already established codebase.

## Current focuses
- Composition over inheritance
- Modular code, dividing game into separable parts
- Physics-based puzzles
- Quest system using [SUQS](https://github.com/sinbad/SUQS)
- Save system using [SPUD](https://github.com/sinbad/SPUD)
- Dialogue system using [DlgSystem](https://github.com/NotYetGames/DlgSystem)
- Interaction System using [InteractionSystem](https://github.com/Ji-Rath/UEInteractSystem/)

Current UE version: 5.5

# Notes
## Physics Simulation
- Creating small physics objects can be glitchy when the player steps over it or run into it.
This was resolved by letting the player capsule overlap the smaller objects.
Then, a small sphere capsule is placed at the base of the player so that the physics objects move
to the side when the player walks through them. Creating a separate object channel helps separate
'background' physics objects from interactable ones.~~~~
- Another issue is when small physics objects are put between a 'rock and a hard place'. They will
stutter and flail around until it finds a way out. Adjusting the Max Depenetration Velocity helps resolve this.
But, this means that the physics object has a chance to phase through objects.
- For interacable physics objects (ones where the player can step up on and move around),
setting the correct mass is extremely important to prevent sudden movements in the object.
- In addition, 'falling off' a physics object can sometimes have the object (or player!) launched in
the air. This can be mitigated by disabling CanCharacterStepUpOn and adjusting 'Perch' and 'Ledge' settings in the Character Movement Component.
- Disabling pawn collision while the player is grabbing an object is the only solution I found to prevent
flying while grabbing a physics object under you. A better solution may be possible.

# Story
## Premise:
After a long day at work, **Player** returns to his modest suburban home. It's the middle of winter, and darkness falls early. A biting chill lingers in the air. The only source of warmth is his cozy living room, bathed in a soft amber glow from the floor lamp by the couch. He moves around his familiar space, performing his nightly routine—but tonight, something feels... off.
## Gameplay:
- After watching TV or eating dinner, it was time to go to bed.
- Before going to bed, the player must turn off all lights/electronics
- Lights cannot be turned back on by the player
- Similar to slender man, a strange creature will start appearing more frequently as more lights go off
- once all lights are turned off, the player must then finally make it to their bed in darkness
- as a bonus, the player forgot their favorite toy at the other side of the house and must retrieve it
- bad ending - player dies rip
- good ending - all lights are off and stuffed animal is retrieved, player sleeps well

## Random scare events
- As the player is turning off the lights, a random light may turn back on..maybe red. An object may be in the middle of the room (like a monster?). Shortly after, the light will go back to normal
- Random footsteps from across the house or outside
- person staring inside from window
- person leaning over corner
- random objects falling over, like a plate, or umbrella
- faintly hear crying from a distance

## Game over events
- if the player gets too close to a scare event (maybe like the monster), the monster should disappear. But shortly after (or when the player turns around), the monster should jump scare the player
- If there is a chase event, the monster should simply jump scare the player when he gets close (idk if i like this idea)

## External Assets Currently Used
- https://elbolilloduro.itch.io/paquete-de-modelos-low-poly-estilo-psx-2
- https://chilly-durango.itch.io/medieval-building-parts
