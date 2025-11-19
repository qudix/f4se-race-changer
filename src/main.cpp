struct Hook_PlayerCharacter
{
	static void LoadGame(RE::PlayerCharacter* a_this, RE::BGSLoadFormBuffer* a_loadGameBuffer)
	{
		_LoadGame(a_this, a_loadGameBuffer);

		if (const auto npc = a_this->GetNPC())
			a_this->charGenRace = npc->GetFormRace();
	}

	static inline REL::HookVFT _LoadGame{ "LoadGame", RE::PlayerCharacter::VTABLE[0], 0x12, LoadGame };
};

F4SE_PLUGIN_LOAD(const F4SE::LoadInterface* a_f4se)
{
	F4SE::Init(a_f4se);

	return true;
}
