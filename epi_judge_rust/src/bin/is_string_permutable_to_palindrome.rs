use std::collections::HashMap;

fn is_string_permutable_to_palindrome(s: String) -> bool {
    let mut map = HashMap::new();
    for c in s.chars() {
        let count = map.entry(c).or_insert(0);
        *count += 1;
    }

    map.values().filter(|count| *count % 2 != 0).count() <= 1
}

fn main() {
    epi_judge_rust::run_tests(
        "is_string_permutable_to_palindrome.tsv",
        |data| -> epi_judge_rust::Result<()> {
            let s = data[0].to_owned();
            let expected = serde_json::from_str::<bool>(&data[1]).unwrap();
            let actual = is_string_permutable_to_palindrome(s);

            epi_judge_rust::try_assert!(actual, expected)
        },
    );
}
