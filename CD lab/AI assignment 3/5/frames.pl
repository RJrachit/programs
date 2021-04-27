frame(name(vehicle), 
    _,
    [engine, brakes, fuel_tank, registration_date],
    []).

frame(name(land),
    isa(vehicle),
    [wheels],
    []).

frame(name(water),
    isa(vehicle),
    [fins],
    []).

frame(name(air),
    isa(vehicle),
    [wings],
    []).

frame(name(road),
    isa(land),
    [registration_date],
    []).

frame(name(rail),
    isa(land),
    [coaches],
    []).

frame(name(kwaski_bajaj),
    isa(road),
    [],
    [wheels]).

frame(name(eicher_mitsubishi),
    isa(road),
    [],
    [wheels]).

frame(name(shatabdi),
    isa(rail),
    [],
    []).

frame(name(frontier),
    isa(rail),
    [],
    []).

frame(name(sea),
    isa(water),
    [navigation_instrument],
    []).

frame(name(river),
    isa(water),
    [seats],
    []).

frame(name(ins_yikrant),
    isa(sea),
    [],
    []).

frame(name(canoe),
    isa(river),
    [],
    []).

frame(name(aircraft),
    isa(air),
    [carrying_capacity],
    []).

frame(name(space),
    isa(air),
    [speed],
    []).

frame(name(iaf_bazz),
    isa(aircraft),
    [],
    []).

frame(name(f_16),
    isa(aircraft),
    [],
    []).

frame(name(sputnik),
    isa(space),
    [],
    []).

frame(name(challenger),
    isa(space),
    [],
    []).


get(Prop, Object) :- frame(name(Object), _, List_of_properties, _), member(Prop, List_of_properties).
get(Prop, Object) :- frame(name(Object), _, _, List_of_defaults), member(Prop, List_of_defaults).
get(Prop, Object) :- frame(name(Object), isa(Parent), _, _), get(Prop, Parent).