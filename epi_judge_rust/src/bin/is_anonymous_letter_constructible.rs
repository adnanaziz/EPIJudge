use std::collections::HashMap;

fn is_anonymous_letter_constructible(letter_text: String, magazine_text: String) -> bool {
    let mut letter_char_count = HashMap::new();
    let mut magazine_char_count = HashMap::new();
    for c in letter_text.chars() {
        let count = letter_char_count.entry(c).or_insert(0);
        *count += 1;
    }

    for c in magazine_text.chars() {
        let count = magazine_char_count.entry(c).or_insert(0);
        *count += 1;
    }

    for (k, v) in letter_char_count.iter() {
        if !magazine_char_count.contains_key(&k) {
            return false;
        } else if v > magazine_char_count.get(&k).unwrap() {
            return false;
        }
    }

    true
}

fn main() {
    epi_judge_rust::run_tests(
        "is_anonymous_letter_constructible.tsv",
        |data| -> epi_judge_rust::Result<()> {
            let letter_text = data[0].to_owned();
            let magazine_text = data[1].to_owned();
            let expected: bool = data[2].parse().unwrap();
            let actual = is_anonymous_letter_constructible(letter_text, magazine_text);

            epi_judge_rust::try_assert!(actual, expected)
        },
    );
}
