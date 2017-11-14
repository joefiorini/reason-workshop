[@bs.module] external reactMarkdown : ReasonReact.reactClass = "react-markdown";

let make = (~source: string, children) =>
  ReasonReact.wrapJsForReason(~reactClass=reactMarkdown, ~props={"source": source}, children);
