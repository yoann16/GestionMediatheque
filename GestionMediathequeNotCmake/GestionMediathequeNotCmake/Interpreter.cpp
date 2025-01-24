#include "Interpreter.h"

namespace
{
	using Word = std::string;
	using WordList = std::vector<Word>;

	WordList splitIntoWord(const Word& input)
	{
		WordList wordList;
		Word currentWord;
		for (char ch : input)
		{
			if (ch != ' ')
				currentWord += ch;
			else if (!currentWord.empty())
			{
				wordList.push_back(currentWord);
				currentWord.clear();
			}
		}
		if (!currentWord.empty())
		{
			wordList.push_back(currentWord);
		}
		return wordList;
	}
}
namespace Library_Manager
{
	Interpreter::Interpreter(CommandManager& commandManager)
		: m_isInitialized(false), m_commandManager(getGlobalCommandManager())
	{
	}
	void Interpreter::init()
	{
		m_isInitialized = true;
	}
	void Interpreter::Input(const std::string& input)
	{
		if (!m_isInitialized)
		{
			throw;
		}

		WordList command = splitIntoWord(input);
		if (command.empty())
		{
			throw std::invalid_argument("No command provided");
		}

		const Word& commandType = command[0];

		try
		{
			m_commandManager.create_Command(commandType, command);
		}
		catch (const UnknownCommandException& e)
		{
			std::cerr<<e.what()<<std::endl; //juste renvoyer un message
		}
	}
	CommandManager& Interpreter:: getCommandManager() { return m_commandManager; }
}
