use serde::Deserialize;
use std::collections::HashMap;
use std::io::BufReader;
use std::iter::FromIterator;

type Result<T> = std::result::Result<T, Box<dyn std::error::Error>>;

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

#[derive(Deserialize, Debug)]
struct Record {
    #[serde(alias = "array(string)")]
    actual: Vec<String>,
    #[serde(alias = "array(array(string))")]
    expected: Vec<Vec<String>>,
}

fn read_test_data(path: &str) -> Result<Vec<Record>> {
    let file = std::fs::File::open(path)?;
    let mut reader = csv::ReaderBuilder::new()
        .delimiter(b'\t')
        .flexible(true)
        .from_reader(BufReader::new(file));
    let mut result: Vec<Record> = vec![];

    for rec in reader.deserialize() {
        let rec: Record = rec?;
        result.push(rec);
    }

    Ok(result)
}

#[test]
fn test_anagrams() {
    let curr_dir = std::env::current_dir().unwrap();
    let curr_dir = curr_dir.to_str().unwrap();
    let path = &format!("{}/{}", curr_dir, "../test_data/anagrams.tsv");
    let data = read_test_data(path).unwrap();
    for tdata in data {
        let out = anagrams(tdata.actual);
        println!("OUT: {:?}", out);
        assert_eq!(out, tdata.expected);
    }
}
