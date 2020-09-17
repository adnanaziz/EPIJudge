fn anagrams(_dictionary: Vec<String>) -> Vec<Vec<String>> {
    vec![vec![]]
}

#[test]
fn test_anagrams() {
    let expected: Vec<Vec<String>> = vec![vec![]];
    assert!(anagrams(vec![]) == expected);
}
