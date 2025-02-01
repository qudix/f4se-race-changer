struct Hook_PlayerCharacter
{
	static void LoadGame(RE::PlayerCharacter* a_this, RE::BGSLoadFormBuffer* a_loadGameBuffer)
	{
		_LoadGame(a_this, a_loadGameBuffer);

		if (const auto npc = a_this->GetNPC())
			a_this->charGenRace = npc->GetFormRace();
	}

	static inline REL::Relocation<decltype(LoadGame)> _LoadGame;

	static void Install()
	{
		REL::Relocation vtbl{ RE::PlayerCharacter::VTABLE[0] };
		_LoadGame = vtbl.write_vfunc(0x12, LoadGame);
	}
};

F4SEPluginLoad(const F4SE::LoadInterface* a_f4se)
{
	F4SE::Init(a_f4se);

	Hook_PlayerCharacter::Install();

	return true;
}
