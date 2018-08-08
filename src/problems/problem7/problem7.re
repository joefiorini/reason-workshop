type shape =
  | Square
  | Circle;

module Shape = {
  module type Shapeable = {let style: ReactDOMRe.Style.t;};
  module type Shape = {let render: string => ReasonReact.reactElement;};
  module Make = (S: Shapeable) : Shape => {
    include S;
    let render = _ => <div style=S.style />;
  };
};

/*
 use the Shape.Make functor to create two new modules:
   Square
   Circle
 and replace the switch statement in Problem7 to render the correct shapes.
  */
type state = {shape};

type action =
  | MakeCircle
  | MakeSquare;

let component = ReasonReact.reducerComponent("Problem4");

let make = _children => {
  ...component,
  initialState: () => {shape: Circle},
  render: ({state, send}) =>
    <div>
      <div>
        <button onClick=(_ => send(MakeCircle))>
          (ReasonReact.string("show circle"))
        </button>
        <button onClick=(_ => send(MakeSquare))>
          (ReasonReact.string("show square"))
        </button>
      </div>
      (
        switch (state.shape) {
        | Circle => <div> (ReasonReact.string("change me to a circle")) </div>
        | Square => <div> (ReasonReact.string("change me to a square")) </div>
        }
      )
    </div>,
};
