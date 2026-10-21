'use client';

import { useState } from 'react';
import { Button } from '@/components/ui/button';
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from '@/components/ui/collapsible';
import { Bars3Icon } from '@heroicons/react/24/outline';

type FilterPanelProps = {
  categories: string[];
  selected: string | null;
  onSelect: (category: string) => void;
  onClear: () => void;
};

function FilterPanelContent({ categories, selected, onSelect, onClear }: FilterPanelProps) {
  return (
    <ul className="space-y-2 px-4 pt-2 pb-4 bg-white rounded-lg shadow-md">
      {categories.map((cat) => (
        <li key={cat}>
          <Button
            variant="ghost"
            className={`w-full justify-start text-sm ${
              selected === cat
                ? 'text-blue-600 border-b border-blue-500'
                : 'text-gray-600 hover:text-gray-800'
            }`}
            onClick={() => onSelect(cat)}
          >
            {cat}
          </Button>
        </li>
      ))}
      {selected && (
        <li>
          <Button
            variant="ghost"
            className="w-full justify-start text-sm text-gray-500 hover:text-gray-700"
            onClick={onClear}
          >
            Clear Filter
          </Button>
        </li>
      )}
    </ul>
  );
}

export function FilterPanel(props: FilterPanelProps) {
  const [isOpen, setIsOpen] = useState(false);

  return (
    <>
      <aside className="hidden md:block w-60 p-4 bg-white rounded-lg">
        <h3 className="text-lg font-medium text-gray-800 mb-4">Filter</h3>
        <FilterPanelContent {...props} />
      </aside>

      <div className="block md:hidden w-full">
        <Collapsible open={isOpen} onOpenChange={setIsOpen}>
          <div className="w-full flex justify-center mb-2">
            <CollapsibleTrigger asChild>
              <Button variant="outline" className="flex items-center gap-2">
                <Bars3Icon className="w-5 h-5" />
                Filters
              </Button>
            </CollapsibleTrigger>
          </div>

          <CollapsibleContent>
            <FilterPanelContent {...props} />
          </CollapsibleContent>
        </Collapsible>
      </div>
    </>
  );
}
