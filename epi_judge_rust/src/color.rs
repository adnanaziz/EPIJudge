pub enum Color<'a> {
    Cyan(&'a str),
    Green(&'a str),
    Red(&'a str),
    Yellow(&'a str),
    Blue(&'a str),
    Magenta(&'a str),
}

impl Color<'_> {
    pub fn make(self) -> String {
        match self {
            Color::Cyan(s) => format!("\x1b[36m{}\x1b[0m", s),
            Color::Green(s) => format!("\x1b[32m{}\x1b[0m", s),
            Color::Red(s) => format!("\x1b[31m{}\x1b[0m", s),
            Color::Yellow(s) => format!("\x1b[33m{}\x1b[0m", s),
            Color::Blue(s) => format!("\x1b[34m{}\x1b[0m", s),
            Color::Magenta(s) => format!("\x1b[35m{}\x1b[0m", s),
        }
    }
}
