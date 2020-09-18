use std::collections::HashMap;

fn is_string_permutable_to_palindrome(s: String) -> bool {
    let mut map = HashMap::new();
    for c in s.chars() {
        let count = map.entry(c).or_insert(0);
        *count += 1;
    }

    map.values().filter(|count| *count % 2 != 0).count() <= 1
}

#[test]
fn test_is_string_permutable_to_palindrome() {
    crate::run_tests(|| {
        let test_data = crate::read_test_data("is_string_permutable_to_palindrome.tsv").unwrap();
        for data in test_data {
            let s = data[0].to_owned();
            let expected = serde_json::from_str::<bool>(&data[1]).unwrap();
            let actual = is_string_permutable_to_palindrome(s);

            assert_eq!(actual, expected);
        }
    });
}
