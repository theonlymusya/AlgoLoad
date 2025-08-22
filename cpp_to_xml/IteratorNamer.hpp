// Новая версия IteratorNamer — без состояния!
class IteratorNamer {
   private:
    // i → depth 0, j → depth 1, k → depth 2, …
    const std::string alphabet = "ijklmnopqrstuvwxyzabcdefgh";

   public:
    // даёт имя для итератора, который в цепочке стоит на позиции `d`
    // при глубине рекурсии `depth`
    std::string nameAt(size_t depth, size_t d) const {
        size_t idx = depth + d;
        if (idx < alphabet.size()) {
            return std::string(1, alphabet[idx]);
        } else {
            return "iter" + std::to_string(idx);
        }
    }
};
