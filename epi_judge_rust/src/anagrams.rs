use serde::Deserialize;
use std::collections::HashMap;
use std::convert::Into;
use std::io::{BufRead, BufReader};
use std::iter::FromIterator;
use std::path::PathBuf;

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
    actual: Vec<String>,
    expected: Vec<Vec<String>>,
    note: String,
}

fn read_test_data<P: Into<PathBuf>>(path: P) -> Result<Vec<Record>> {
    let file = std::fs::File::open(path.into())?;
    let reader = BufReader::new(file);
    let mut result: Vec<Record> = vec![];
    let mut lines = reader.lines();

    // skip header row
    lines.next();

    for line in lines {
        let line = line?;
        let row = line.split('\t').collect::<Vec<_>>();
        assert_eq!(row.len(), 3);
        let rec = Record {
            actual: serde_json::from_str::<Vec<String>>(row[0])?,
            expected: serde_json::from_str::<Vec<Vec<String>>>(row[1])?,
            note: row[2].to_string(),
        };
        result.push(rec);
    }

    Ok(result)
}

fn run_tests<F>(func: F)
where
    F: FnOnce(),
{
    // TODO measure elapsed time
    // TODO handle errors: RuntimeError, TimeLimitExceeded, OtherError
    func();
}

fn get_test_data_path(filename: &str) -> Result<PathBuf> {
    let mut path = std::env::current_dir()?;
    path.push("../test_data/");
    path.push(filename);
    Ok(path)
}

#[test]
fn test_anagrams() {
    run_tests(|| {
        let data = read_test_data(get_test_data_path("anagrams.tsv").unwrap()).unwrap();
        for tdata in data {
            let mut tdata = tdata;
            let mut out = anagrams(tdata.actual);
            out.sort();
            tdata.expected.sort();
            assert_eq!(out, tdata.expected);
        }
    });
}

// ***************** Deserialization Traits **************************
