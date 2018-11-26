type item = {
  title: string,
  completed: bool
}

type state = {
  items: list(item),
}

type action = 
  | AddItem

let newItem = () => { title: "Clicked a Button", completed: true };



let string = ReasonReact.string;

let component = ReasonReact.reducerComponent("Todo");

let make = ( _children) => {
     ...component,
      initialState: () => {
        items: [
          { title: "Write something to do ", completed: false },
        ],
      },
        reducer: (action, state) => {
            switch action {
            | AddItem => ReasonReact.Update({ items: [newItem() , ...state.items]})
            }
        },

        render: (self) => {
          let title = <h2 className="header" >(string("ReasonML! Todo"))</h2>;
          let numItems = List.length(self.state.items);
        <div>
          <div className="container" >
            (title)
            <button className="btn" onClick=((e) =>self.send(AddItem)) >
              (string("Add Something"))
            </button>
            <input placeholder="Enter todo..." className="search__input"
            />
            <div className="items" >
              <h4>(string("No Todo"))</h4>
              </div>
              <div className="footer" >
              <h3>(string(string_of_int(numItems) ++ " Items"))</h3>
             </div>
          </div>
        </div>;
        }

}
