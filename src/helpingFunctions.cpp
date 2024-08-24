#include "helpingFunctions.h"

namespace HF {

bool IsSuitablePath(const std::filesystem::directory_entry& file) {
  return (std::filesystem::is_directory(file) && !file.path().string().ends_with("cmake-build-debug")
          && !file.path().string().ends_with(".idea"));
}

std::string GetTextFromFile(const std::filesystem::path& file_path) {
  std::ifstream file(file_path);
  std::string to_return;
  std::getline(file, to_return, '\0');
  return to_return;
}
bool IsProgrammingFile(const std::string& path) {
  auto fe = path.substr(path.find_last_of('.') + 1);
  return (fe == "c" || fe == "cpp" || fe == "h" || fe == "hpp");
}

void GetFiles(std::string& root, std::vector<std::filesystem::path>& files) {
  try {
    for (auto& file : std::filesystem::directory_iterator(root)) {
      if (IsSuitablePath(file)) {
        std::string fp = file.path().string();
        GetFiles(fp, files);
      } else if (IsProgrammingFile(file.path().string())) {
        files.emplace_back(file.path().string());
      }
    }
  } catch (const std::filesystem::__cxx11::filesystem_error&) {
    std::cout << "incorrect path of project, try again" << '\n';
    UI::AskDirectoryPath();
    root = UI::ReadPath();
    GetFiles(root, files);
  }
}

Texts MakeTextsFromFiles(const std::vector<std::filesystem::path>& files) {
  Texts texts;
  texts.reserve(files.size());
  std::transform(files.begin(), files.end(), std::inserter(texts, texts.end()),
                 [](const std::filesystem::path& file) {
                   return std::make_pair(file, GetTextFromFile(file));
                 });
  return texts;
}

std::vector<std::string> SplitWordsSnakeCase(std::string_view str) {
  std::string word;
  std::vector<std::string> words;
  for (auto c : str) {
    if (c != '_') {
      word += c;
    } else {
      words.push_back(word);
      word.clear();
    }
  }
  if (!word.empty()) {
    words.push_back(word);
  }
  return words;
}

void LogForFindings(const std::sregex_iterator& it, int pos_of_pushing) {
  std::cout << "string: " << it->str(0) << " name: " << it->str(pos_of_pushing) << std::endl;
}

void LogForWordsSpliting(const std::vector<std::string>& words,
                         std::string_view str) {
  std::cout << "Original word is: " << str;
  std::copy(words.begin(), words.end(),
            std::ostream_iterator<std::string>(std::cout, " "));
}

std::vector<std::string> SplitWordsPascalOrCamel(std::string_view str) {
  std::vector<std::string> words;
  words.reserve(str.size());

  std::string word;
  for (char ch : str) {
    if (std::isupper(static_cast<unsigned char>(ch)) && !word.empty()) {
      words.push_back(std::move(word));
      word.clear();
    }
    word += static_cast<char>(std::tolower((ch)));
  }

  if (!word.empty()) {
    words.push_back(std::move(word));
  }
  LogForWordsSpliting(words, str);
  words.shrink_to_fit();
  return words;
}

std::string MakeSnakeCase(const std::vector<std::string>& splited) {
  if (splited.empty()) {
    return "";
  }

  std::string result;
  size_t total_size = 0;
  for (const auto& word : splited) {
    total_size += word.size() + 1;
  }
  result.reserve(total_size - 1);

  for (const auto& word : splited) {
    result.append(word).append("_");
  }

  result.pop_back();
  return result;
}

std::string MakeCamelCase(const std::vector<std::string>& splited) {
  std::string result;
  bool is_first_word = true;
  for (const auto& word : splited) {
    bool is_first_letter = true;
    for (auto c : word) {
      if (is_first_letter && !is_first_word) {
        result += static_cast<char>(toupper(c));
        is_first_letter = false;
      } else {
        result += c;
      }
    }
    is_first_word = false;
  }
  return result;
}

std::string MakePascalCase(const std::vector<std::string>& splited) {
  std::string result;
  for (const auto& word : splited) {
    bool is_first_letter = true;
    for (auto c : word) {
      if (is_first_letter) {
        result += static_cast<char>(toupper(c));
        is_first_letter = false;
      } else {
        result += c;
      }
    }
  }
  return result;
}

std::string MakeNewName(const std::vector<std::string>& splited, Style style) {
  std::string to_return;
  size_t size_of_words = 0;
  for (const auto& word : splited) {
    size_of_words += word.size() + 1;
  }
  to_return.reserve(size_of_words);

  if (style == snake_case) {
    to_return = MakeSnakeCase(splited);
  } else if (style == camelCase) {
    to_return = MakeCamelCase(splited);
  } else if (style == PascalCase) {
    to_return = MakePascalCase(splited);
  }
  return to_return;
}
}
