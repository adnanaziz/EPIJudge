use std::collections::HashMap;
use std::iter::FromIterator;

fn anagrams(dictionary: Vec<String>) -> Vec<Vec<String>> {
    let mut map: HashMap<String, Vec<String>> = HashMap::new();
    for word in dictionary {
        let mut sorted = word.chars().collect::<Vec<_>>();
        sorted.sort();
        let sorted = String::from_iter(sorted);
        let e = map.entry(sorted).or_default();
        e.push(word);
    }

    map.values()
        .filter(|v| v.len() >= 2)
        .map(|v| v.clone())
        .collect::<Vec<Vec<String>>>()
}

#[test]
fn test_anagrams() {
    crate::run_tests(|| {
        let test_data = crate::read_test_data("anagrams.tsv").unwrap();
        for data in test_data {
            let dictionary = serde_json::from_str::<Vec<String>>(&data[0]).unwrap();
            let mut expected = serde_json::from_str::<Vec<Vec<String>>>(&data[1]).unwrap();
            let mut actual = anagrams(dictionary);

            actual.sort();
            expected.sort();

            assert_eq!(actual, expected);
        }
    });
}
