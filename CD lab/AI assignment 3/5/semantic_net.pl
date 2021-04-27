isa(land, vehicle).
isa(water, vehicle).
isa(air, vehicle).

isa(road, land).
isa(rail, land).

isa(sea, water).
isa(river, water).

isa(aircraft, air).
isa(space, air).


isa(kwaski_bajaj, road).
isa(eicher_mitsibishi, road).
isa(shatabdi, rail).
isa(frontier, rail).

isa(ins_vikrant, sea).
isa(canoe, river).

isa(iaf_bazz, air).
isa(f_16, air).
isa(sputnik, space).
isa(challenger, space).


hasprop(vehicle, engine, true).
hasprop(vehicle, brakes, true).
hasprop(vehicle, fuel_tank, true).
hasprop(vehicle, registration_date, true).

hasprop(land, wheels, true).
hasprop(water, fins, true).
hasprop(air, wings, true).

hasprop(road, registration_date, true).
hasprop(rail, coaches, true).

hasprop(sea, navigation_instrument, true).
hasprop(river, seats, true).

hasprop(aircraft, carrying_capacity , true).
hasprop(space, speed, true).


hasprop(kwaski_bajaj, wheels, 2).
hasprop(eicher_mitsibishi, wheels, 4).


hasproperty(Object, Property, Value) :- hasprop(Object, Property, Value).
hasproperty(Object, Property, Value) :- isa(Object, Parent), hasproperty(Parent, Property, Value).
