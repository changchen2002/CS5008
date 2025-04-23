import time

# -------------------------------
# KMP Algorithm Implementation
# -------------------------------
def kmp_compute_lps(pattern):
    """
    Compute the longest prefix that is also a suffix (LPS) array for KMP.
    """
    lps = [0] * len(pattern)
    j = 0  # length of the previous longest prefix suffix
    for i in range(1, len(pattern)):
        while j > 0 and pattern[i] != pattern[j]:
            j = lps[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
            lps[i] = j
        else:
            lps[i] = 0
    return lps

def kmp_search(text, pattern):
    """
    Perform KMP pattern matching.
    Returns the count of occurrences and a list of starting indices.
    """
    if pattern == "":
        return 0, []
    
    lps = kmp_compute_lps(pattern)
    count = 0
    indices = []
    j = 0  # index for pattern
    
    for i in range(len(text)):  # index for text
        while j > 0 and text[i] != pattern[j]:
            j = lps[j - 1]
        if text[i] == pattern[j]:
            j += 1
        if j == len(pattern):
            indices.append(i - j + 1)
            count += 1
            j = lps[j - 1]
    return count, indices

# -----------------------------------------
# Boyer–Moore Algorithm (Bad-Character Rule)
# -----------------------------------------
def boyer_moore_preprocess_bad_character(pattern):
    """
    Preprocess the pattern to create the bad character heuristic table.
    Returns a dictionary mapping a character to its last occurrence index in the pattern.
    """
    bad_char_table = {}
    for index, char in enumerate(pattern):
        bad_char_table[char] = index
    return bad_char_table

def boyer_moore_search(text, pattern):
    """
    Perform Boyer-Moore pattern matching using the bad-character heuristic.
    Returns the count of occurrences and a list of starting indices.
    """
    m = len(pattern)
    n = len(text)
    if m == 0:
        return 0, []
    
    bad_char_table = boyer_moore_preprocess_bad_character(pattern)
    count = 0
    indices = []
    s = 0  # shift of the pattern with respect to text
    
    while s <= n - m:
        j = m - 1
        while j >= 0 and pattern[j] == text[s + j]:
            j -= 1
        if j < 0:
            indices.append(s)
            count += 1
            if s + m < n:
                s += m - bad_char_table.get(text[s + m], -1)
            else:
                s += 1
        else:
            shift = max(1, j - bad_char_table.get(text[s + j], -1))
            s += shift
    return count, indices

# -----------------------------------------
# Helper Function: Read Articles from Files
# -----------------------------------------
def read_articles_from_fixed_files():
    """
    Reads three articles from files '1.txt', '2.txt', '3.txt' located in the same directory.
    Returns a dictionary mapping article titles to article content.
    """
    articles = {}
    file_names = ["NVIDIA to Manufacture American-Made AI Supercomputers in US for First Time.txt", 
                  "Nvidia to mass produce AI supercomputers in Texas as part of $500 billion U.S. push.txt", 
                  "OpenAI debuts its GPT-4.1 flagship AI model.txt"]
    for file_name in file_names:
        try:
            with open(file_name, 'r', encoding='utf-8') as f:
                content = f.read()
            # Use the file name (without extension) as the article title, or change as needed.
            title = f"Article {file_name.split('.')[0]}"
            articles[title] = content
        except Exception as e:
            print(f"Error reading file '{file_name}': {e}")
    return articles

# -----------------------------------------
# Main Simulation and Runtime Measurement
# -----------------------------------------
def main():
    # Read articles from fixed files: 1.txt, 2.txt, 3.txt.
    articles = read_articles_from_fixed_files()
    
    if not articles:
        print("No articles were loaded. Exiting.")
        return

    # Ask the user for the keyword to search
    keyword = input("Enter the keyword to search for: ").strip()
    if not keyword:
        print("Keyword is empty. Exiting.")
        return

    # Measure runtime and count keyword occurrences using KMP.
    start_time = time.perf_counter()
    kmp_frequency = {}
    for title, text in articles.items():
        count, _ = kmp_search(text.lower(), keyword.lower())
        kmp_frequency[title] = count
    kmp_runtime = time.perf_counter() - start_time

    # Measure runtime and count keyword occurrences using Boyer-Moore.
    start_time = time.perf_counter()
    bm_frequency = {}
    for title, text in articles.items():
        count, _ = boyer_moore_search(text.lower(), keyword.lower())
        bm_frequency[title] = count
    bm_runtime = time.perf_counter() - start_time

    # Print results for KMP.
    print("\nKMP Keyword Frequencies:")
    for title, count in kmp_frequency.items():
        print(f"{title}: {count} occurrences")
    print(f"KMP Total Runtime: {kmp_runtime:.6f} seconds\n")

    # Print results for Boyer-Moore.
    print("Boyer-Moore Keyword Frequencies:")
    for title, count in bm_frequency.items():
        print(f"{title}: {count} occurrences")
    print(f"Boyer-Moore Total Runtime: {bm_runtime:.6f} seconds\n")

    # Sort articles by keyword frequency (using KMP results) for ranking.
    sorted_articles = sorted(articles.items(), key=lambda item: kmp_frequency[item[0]], reverse=True)
    
    print("Articles Sorted by Keyword Frequency (using KMP counts):")
    for title, _ in sorted_articles:
        print(f"{title} (keyword occurrences: {kmp_frequency[title]})")

if __name__ == "__main__":
    main()