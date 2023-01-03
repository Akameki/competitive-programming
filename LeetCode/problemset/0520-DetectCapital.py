class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word == word.upper() or word == word.lower() or word[0].isupper() and word[1:].islower()