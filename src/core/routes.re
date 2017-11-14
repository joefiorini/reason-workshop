open ReactRouter;

let containerStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~height="100vh",
    ~minHeight="100vh",
    ~width="100vw",
    ~maxWidth="100vw",
    ()
  );

let navStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="column",
    ~height="100%",
    ~minHeight="100vh",
    ~minWidth="20%",
    ~padding="5px",
    ~overflow="scroll",
    ()
  );

let appStyle = ReactDOMRe.Style.make(~height="100%", ~width="100%", ());

let createProblemView = (description, problem, _) => <ProblemView description problem />;

let links = [|
  ("/problems/1", ReasonReact.stringToElement("Problem 1")),
  ("/problems/2", ReasonReact.stringToElement("Problem 2")),
  ("/problems/3", ReasonReact.stringToElement("Problem 3")),
  ("/problems/4", ReasonReact.stringToElement("Problem 4")),
  ("/problems/5", ReasonReact.stringToElement("Problem 5")),
  ("/problems/6", ReasonReact.stringToElement("Problem 6")),
  ("/problems/7", ReasonReact.stringToElement("Problem 7")),
  ("/problems/8", ReasonReact.stringToElement("Problem 8")),
  ("/problems/9", ReasonReact.stringToElement("Problem 9")),
  ("/problems/10", ReasonReact.stringToElement("Problem 10"))
|];

type problem = {
  link: string,
  description: string,
  problem: unit => ReasonReact.reactElement
};

let problems = [|
  {link: "/", description: Problem1Description.src, problem: (_) => <Problem1 />},
  {link: "/problems/1", description: Problem1Description.src, problem: (_) => <Problem1 />},
  {link: "/problems/2", description: Problem2Description.src, problem: (_) => <Problem2 />},
  {link: "/problems/3", description: Problem3Description.src, problem: (_) => <Problem3 />},
  {link: "/problems/4", description: Problem4Description.src, problem: (_) => <Problem4 />},
  {link: "/problems/5", description: Problem5Description.src, problem: (_) => <Problem5 />},
  {link: "/problems/6", description: Problem6Description.src, problem: (_) => <Problem6 />},
  {link: "/problems/7", description: Problem7Description.src, problem: (_) => <Problem7 />},
  {link: "/problems/8", description: Problem8Description.src, problem: (_) => <Problem8 />},
  {link: "/problems/9", description: Problem9Description.src, problem: (_) => <Problem9 />},
  {link: "/problems/10", description: Problem10Description.src, problem: (_) => <Problem10 />}
|];

let component = ReasonReact.statelessComponent("Routes");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div className="pure-g" style=containerStyle>
      <div className="pure-u-1-8" style=(ReactDOMRe.Style.make(~background="#f5f2f0", ()))>
        <ul
          style=(
            ReactDOMRe.Style.make(~lineHeight="1.4", ~listStyle="none", ~paddingLeft="15px", ())
          )>
          (
            ReasonReact.arrayToElement(
              Array.map(((href, label)) => <li key=href> <a href> label </a> </li>, links)
            )
          )
        </ul>
      </div>
      <div className="pure-u-7-8">
        (
          ReasonReact.arrayToElement(
            Array.map(
              ({link, description, problem}) =>
                <Route
                  key=link
                  path=link
                  component=(createProblemView(description, problem))
                  exact=true
                />,
              problems
            )
          )
        )
      </div>
    </div>
};
