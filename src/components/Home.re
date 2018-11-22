
/* Define State */
type state = {
    count: int,
    show: bool
}

type action =
  | Click
  | Toggle;

  let component = ReasonReact.reducerComponent("Home");


let make = _children => {
    ...component,
    /* Set the initial state */
    initialState: () => { count: 0, show: true },

    reducer: (action, state) =>
        switch(action) {
        | Click => ReasonReact.Update({...state, count: state.count + 1 })
        | Toggle => ReasonReact.Update({...state, show: !state.show })
        },

        render: self => {
            let message = "You've clicked this button " ++ string_of_int(self.state.count) ++ " times";
            let greeting = "You are old enough";
            let toggleStr = (ReasonReact.string("Toggle"));
            let colorStr = <h4>(ReasonReact.string("Colors"))</h4>;
            <div>
            (
                self.state.count >= 15 ? <h3>(ReasonReact.string(greeting))</h3> : ReasonReact.null
            )
                <button className="btn_1" onClick=(_e => self.send(Click)) >
                    (ReasonReact.string(message))
                </button>

                <button onClick=(_e => self.send(Toggle)) >
                    (toggleStr)
                </button>

                (
                    self.state.show ? (colorStr) : ReasonReact.null
                )

            </div>;
        },
}