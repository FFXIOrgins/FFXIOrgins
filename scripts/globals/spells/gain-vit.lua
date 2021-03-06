--------------------------------------
-- 	Spell: Gain-VIT
-- 	Boosts VIT for the Caster
--------------------------------------
 
require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/magic");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function OnMagicCastingCheck(caster,target,spell)
	return 0;
end;

function onSpellCast(caster,target,spell)
	local effect = EFFECT_VIT_BOOST;
	doBoostGain(caster,target,spell,effect);
	return effect;
end;